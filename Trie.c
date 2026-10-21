/*
  Copyright 2026 Isac Jônatas de Oliveira

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/










#pragma once

#include "Mem.c"
#include "Types.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

struct Trie_Node {
  u64 ID;
  u64 BitMap;
  u64 ChildrenCapacity;
  struct Trie_Node **Children;
};

typedef struct {
  u64 EmptyNodesId;
  Arena *Arena;
  struct Trie_Node Trie;
} Trie;

static u64 Trie_PopCount(u64 Value) {
  return (u64)__builtin_popcountll((unsigned long long)Value);
}

static u64 Trie_ChildIndex(u64 BitMap, u64 BitPosition) {
  return Trie_PopCount(BitMap & (BitPosition - 1));
}

static struct Trie_Node *Trie_AllocNode(Arena *ArenaPtr, u64 EmptyNodesId) {
  struct Trie_Node *Node = Arena_Alloc(
    ArenaPtr, sizeof(struct Trie_Node) + sizeof(struct Trie_Node *));

  if (!Node)
    return NULL;

  Node->ID = EmptyNodesId;
  Node->BitMap = 0;
  Node->ChildrenCapacity = 1;
  Node->Children = (struct Trie_Node **)((byte_pt)Node + sizeof(*Node));
  Node->Children[0] = NULL;
  return Node;
}

Trie *Trie_Init(u64 EmptyNodesId, Arena *ArenaPtr) {
  if (!ArenaPtr)
    return NULL;

  Trie *NewTrie = Arena_Alloc(ArenaPtr, sizeof(Trie) + sizeof(struct Trie_Node *));
  if (!NewTrie)
    return NULL;

  NewTrie->EmptyNodesId = EmptyNodesId;
  NewTrie->Arena = ArenaPtr;
  NewTrie->Trie.ID = EmptyNodesId;
  NewTrie->Trie.BitMap = 0;
  NewTrie->Trie.ChildrenCapacity = 1;
  NewTrie->Trie.Children = (struct Trie_Node **)((byte_pt)NewTrie + sizeof(Trie));
  NewTrie->Trie.Children[0] = NULL;
  return NewTrie;
}

insert_result Trie_Insert(Trie *TriePtr, u64 Id, i8 *Key, u64 KeyLength) {
  if (!TriePtr || !TriePtr->Arena || !Key || KeyLength == 0)
    return failed_to_insert;

  struct Trie_Node *CurrentNode = &TriePtr->Trie;

  for (u64 Index = 0; Index < KeyLength; Index++) {
    /* Treat key bytes as unsigned so values 128..255 are valid as well. */
    u8 Character = (u8)Key[Index];
    u64 BitPosition = UINT64_C(1) << Character;
    u64 OldBitmap = CurrentNode->BitMap;
    u64 ChildIndex = Trie_ChildIndex(OldBitmap, BitPosition);

    if (OldBitmap & BitPosition) {
      CurrentNode = CurrentNode->Children[ChildIndex];
      if (!CurrentNode)
        return failed_to_insert;
      continue;
    }

    u64 ChildCount = Trie_PopCount(OldBitmap);
    if (ChildCount > CurrentNode->ChildrenCapacity)
      return failed_to_insert;

    /* Allocate first so failure never leaves a shifted or half-updated node. */
    struct Trie_Node *NewNode = Trie_AllocNode(TriePtr->Arena, TriePtr->EmptyNodesId);
    if (!NewNode)
      return failed_to_insert;

    if (ChildCount == CurrentNode->ChildrenCapacity) {
      if (CurrentNode->ChildrenCapacity > UINT64_MAX / 2 ||
          CurrentNode->ChildrenCapacity * 2 > SIZE_MAX / sizeof(*CurrentNode->Children))
        return failed_to_insert;

      u64 NewCapacity = CurrentNode->ChildrenCapacity * 2;
      struct Trie_Node **NewChildren = Arena_Alloc(
        TriePtr->Arena, (size_t)(sizeof(*NewChildren) * NewCapacity));
      if (!NewChildren)
        return failed_to_insert;

      for (u64 I = 0; I < ChildIndex; I++)
        NewChildren[I] = CurrentNode->Children[I];
      for (u64 I = ChildIndex; I < ChildCount; I++)
        NewChildren[I + 1] = CurrentNode->Children[I];

      CurrentNode->Children = NewChildren;
      CurrentNode->ChildrenCapacity = NewCapacity;
    } else {
      for (u64 I = ChildCount; I > ChildIndex; I--)
        CurrentNode->Children[I] = CurrentNode->Children[I - 1];
    }

    CurrentNode->Children[ChildIndex] = NewNode;
    CurrentNode->BitMap = OldBitmap | BitPosition;
    CurrentNode = NewNode;
  }

  if (CurrentNode->ID != TriePtr->EmptyNodesId)
    return already_exists;

  CurrentNode->ID = Id;
  return new_node;
}

u64 Trie_Search(Trie *TriePtr, i8 *Key, u64 KeyLength) {
  if (!TriePtr || !Key || KeyLength == 0)
    return TriePtr ? TriePtr->EmptyNodesId : 0;

  struct Trie_Node *CurrentNode = &TriePtr->Trie;
  for (u64 Index = 0; Index < KeyLength; Index++) {
    u8 Character = (u8)Key[Index];
    u64 BitPosition = UINT64_C(1) << Character;

    if (!(CurrentNode->BitMap & BitPosition))
      return TriePtr->EmptyNodesId;

    u64 ChildIndex = Trie_ChildIndex(CurrentNode->BitMap, BitPosition);
    CurrentNode = CurrentNode->Children[ChildIndex];
    if (!CurrentNode)
      return TriePtr->EmptyNodesId;
  }

  return CurrentNode->ID;
}