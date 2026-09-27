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

struct Trie_Node {
  u64 ID;
  u64 BitMap;
  struct Trie_Node **Children;
};

typedef struct{
  struct Trie_Node Trie;
  Arena *Arena;
} Trie;

Trie *Trie_Init(u64 EmptyNodesId, Arena *ArenaPtr) {
  Trie *New_Trie = Arena_Alloc(
    ArenaPtr, sizeof(Trie) + sizeof(struct Trie_Node *));

  if (!New_Trie)
    return NULL;
  
  New_Trie->Trie.BitMap = 0;
  *(New_Trie->Trie.Children) = (struct Trie_Node *) ((byte_pt)New_Trie + sizeof(Trie));
  New_Trie->Trie.ID = EmptyNodesId;

  New_Trie->Arena = ArenaPtr;

  return New_Trie;
};


