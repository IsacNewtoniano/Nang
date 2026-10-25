#include "Handlers/Types.h"
#include "Librarys/Timer.c"
#include "Librarys/Mem.c"
#include "Librarys/Trie.c"
#include "Handlers/Utils.h"

#include <windows.h>
#include <stdio.h>

#define Tests_Limit 1

int main() {
  Initialize_Timer(3500000000);

  Arena *arena = Init_Arena(GB(1), MB(1));
  if (!arena){
    printf("ERROR: Arena initialization\n");
    return 1;
  }
  
  Trie *trie = Trie_Init(0, arena);
  if (!trie){
    printf("ERROR: Trie initialization\n");
    return 1;
  }

  i8 Key[4] = "\0\0\0\0";
  
  f64 Total_Time_Of_D1_Insert = 0.0;
  f64 Total_Time_Of_D1_Search = 0.0;

  f64 Total_Time_Of_D2_Insert = 0.0;
  f64 Total_Time_Of_D2_Search = 0.0;

  f64 Total_Time_Of_D3_Insert = 0.0;
  f64 Total_Time_Of_D3_Search = 0.0;

  f64 Total_Time_Of_D4_Insert = 0.0;
  f64 Total_Time_Of_D4_Search = 0.0;


  f64 Total_Time_Of_Tests = 0.0;

  u64 D1already_exists = 0;
  u64 D1new_node = 0;
  u64 D1failed_to_insert = 0;
  u64 D1failed_Search = 0;

  u64 D2already_exists = 0;
  u64 D2new_node = 0;
  u64 D2failed_to_insert = 0;
  u64 D2failed_Search = 0;

  u64 D3already_exists = 0;
  u64 D3new_node = 0;
  u64 D3failed_to_insert = 0;
  u64 D3failed_Search = 0;

  u64 D4already_exists = 0;
  u64 D4new_node = 0;
  u64 D4failed_to_insert = 0;
  u64 D4failed_Search = 0;

  u64 Time_Init = init_time();
  for (u64 test = 0; test <= Tests_Limit; test++) {
    u64 Id = 1;

    u64 TimeD1_Init = init_time();
    /* 1 dígits */
    for (u64 Index = 0; Index < 63; Index++) {
      Key[0] = Index;

      insert_result result = Trie_Insert(trie, Id++, Key, 1);

      if (result == already_exists) {
        D1already_exists += 1;
      } else if (result == new_node) {
        D1new_node += 1;
      } else {
        D1failed_to_insert += 1;
      }
      // Trie_Insert(trie, Id++, Key, 1);

    }
    u64 TimeD1_End = end_time();
    Total_Time_Of_D1_Insert += ct_ns(TimeD1_End-TimeD1_Init);

    u64 TimeD2_Init = init_time();

    /* 2 dígits */
    Key[0] = 0;
    Key[1] = 0;

    for (u64 Index = 0; Index < 63ULL * 63; Index++) {

      insert_result result = Trie_Insert(trie, Id++, Key, 2);

      if (result == already_exists) {
        D2already_exists += 1;
      } else if (result == new_node) {
        D2new_node += 1;
      } else {
        D2failed_to_insert += 1;
      }
      // Trie_Insert(trie, Id++, Key, 2);

      if (++Key[1] == 63) {
        Key[1] = 0;
        Key[0]++;
      }
    }
    u64 TimeD2_End = end_time();
    Total_Time_Of_D2_Insert += ct_ns(TimeD2_End-TimeD2_Init);

    u64 TimeD3_Init = init_time();


    /* 3 dígits */
    Key[0] = 0;
    Key[1] = 0;
    Key[2] = 0;

    for (u64 Index = 0; Index < 63ULL * 63 * 63; Index++) {

      insert_result result = Trie_Insert(trie, Id++, Key, 3);

      if (result == already_exists) {
        D3already_exists += 1;
      } else if (result == new_node) {
        D3new_node += 1;
      } else {
        D3failed_to_insert += 1;
      }
      // Trie_Insert(trie, Id++, Key, 3);

      if (++Key[2] == 63) {
        Key[2] = 0;

        if (++Key[1] == 63) {
          Key[1] = 0;
          Key[0]++;
        }
      }
    }
    u64 TimeD3_End = end_time();
    Total_Time_Of_D3_Insert += ct_ns(TimeD3_End-TimeD3_Init);

    u64 TimeD4_Init = init_time();

    /* 4 dígits */
    Key[0] = 0;
    Key[1] = 0;
    Key[2] = 0;
    Key[3] = 0;

    for (u64 Index = 0; Index < 63ULL * 63 * 63 * 63; Index++) {

      insert_result result = Trie_Insert(trie, Id++, Key, 4);

      if (result == already_exists) {
        D4already_exists += 1;
      } else if (result == new_node) {
        D4new_node += 1;
      } else {
        D4failed_to_insert += 1;
      }
      // Trie_Insert(trie, Id++, Key, 4);

      if (++Key[3] == 63) {
        Key[3] = 0;

        if (++Key[2] == 63) {
          Key[2] = 0;

          if (++Key[1] == 63) {
            Key[1] = 0;
            Key[0]++;
          }
        }
      }
    }
    u64 TimeD4_End = end_time();
    Total_Time_Of_D4_Insert += ct_ns(TimeD4_End-TimeD4_Init);

    TimeD1_Init = init_time();

    /* 1 dígits */
    for (u64 Index = 0; Index < 63; Index++) {
      Key[0] = Index;
      u64 result = Trie_Search(trie, Key, 1);
      if (result == 0)
        D1failed_Search += 1;
      // Trie_Search(trie, Key, 1);
    }
    TimeD1_End = end_time();
    Total_Time_Of_D1_Search += ct_ns(TimeD1_End-TimeD1_Init);

    TimeD2_Init = init_time();

    /* 2 dígits */
    Key[0] = 0;
    Key[1] = 0;

    for (u64 Index = 0; Index < 63ULL * 63; Index++) {

      u64 result = Trie_Search(trie, Key, 2);
      if (result == 0)
        D2failed_Search += 1;
      // Trie_Search(trie, Key, 2);

      if (++Key[1] == 63) {
        Key[1] = 0;
        Key[0]++;
      }
    }
    TimeD2_End = end_time();
    Total_Time_Of_D2_Search += ct_ns(TimeD2_End-TimeD2_Init);

    TimeD3_Init = init_time();


    /* 3 dígits */
    Key[0] = 0;
    Key[1] = 0;
    Key[2] = 0;

    for (u64 Index = 0; Index < 63ULL * 63 * 63; Index++) {

      u64 result = Trie_Search(trie, Key, 3);
      if (result == 0)
        D3failed_Search += 1;
      // Trie_Search(trie, Key, 3);

      if (++Key[2] == 63) {
        Key[2] = 0;

        if (++Key[1] == 63) {
          Key[1] = 0;
          Key[0]++;
        }
      }
    }
    TimeD3_End = end_time();
    Total_Time_Of_D3_Search += ct_ns(TimeD3_End-TimeD3_Init);

    TimeD4_Init = init_time();

    /* 4 dígits */
    Key[0] = 0;
    Key[1] = 0;
    Key[2] = 0;
    Key[3] = 0;

    for (u64 Index = 0; Index < 63ULL * 63 * 63 * 63; Index++) {

      u64 result = Trie_Search(trie, Key, 4);
      if (result == 0)
        D4failed_Search += 1;

      //Trie_Search(trie, Key, 4);

      if (++Key[3] == 63) {
        Key[3] = 0;

        if (++Key[2] == 63) {
          Key[2] = 0;

          if (++Key[1] == 63) {
            Key[1] = 0;
            Key[0]++;
          }
        }
      }
    }
    TimeD4_End = end_time();
    Total_Time_Of_D4_Search += ct_ns(TimeD4_End-TimeD4_Init);

    Arena_Offset(arena, 0);
  }
  u64 Time_End = end_time();
  
  Total_Time_Of_Tests = ct_s(Time_End - Time_Init);
  SetConsoleOutputCP(CP_UTF8);



  printf("BENCHMARK TRIE WITH: \n");
  printf("         63 769 986 characters inserted\n");
  printf("         63         strings of 1 character\n");
  printf("         3.969      strings of 2 character\n");
  printf("         250.047    strings of 3 character\n");
  printf("         15.752.961 strings of 4 character\n");
  printf("         \n%u: Repeats\n", Tests_Limit);
  printf("         MEDIUM RESULTS\n");

  printf("         \n1 character\n");
  printf("         %.7f ns: Medium INSERT Time Per String\n", Total_Time_Of_D1_Insert / (f64)Tests_Limit / 63);
  printf("         %.7f ns: Medium SEARCH Time Per String\n", Total_Time_Of_D1_Search / (f64)Tests_Limit / 63);
  printf("         %.7f µs: TOTAL Time\n", Total_Time_Of_D1_Search + Total_Time_Of_D1_Insert);
  printf("      TOTAL New    Node      : %llu\n", D1new_node);
  printf("      TOTAL Failed to Insert : %llu\n", D1failed_to_insert);
  printf("      TOTAL Alredy Exist     : %llu\n", D1already_exists);
  printf("      TOTAL Failed to Search : %llu\n", D1failed_Search);

  printf("         \n2 character\n");
  printf("         %.7f ns: Medium INSERT Time Per String\n", Total_Time_Of_D2_Insert / (f64)Tests_Limit / 3969);
  printf("         %.7f ns: Medium SEARCH Time Per String\n", Total_Time_Of_D2_Search / (f64)Tests_Limit / 3969);
  printf("         %.7f µs: TOTAL Time\n", Total_Time_Of_D2_Search + Total_Time_Of_D2_Insert);
  printf("      TOTAL New    Node      : %llu\n", D2new_node);
  printf("      TOTAL Failed to Insert : %llu\n", D2failed_to_insert);
  printf("      TOTAL Alredy Exist     : %llu\n", D2already_exists);
  printf("      TOTAL Failed to Search : %llu\n", D2failed_Search);

  printf("         \n3 character\n");
  printf("         %.7f ns: Medium INSERT Time Per String\n", Total_Time_Of_D3_Insert / (f64)Tests_Limit / 250047);
  printf("         %.7f ns: Medium SEARCH Time Per String\n", Total_Time_Of_D3_Search / (f64)Tests_Limit / 250047);
  printf("         %.7f ms: TOTAL Time\n", Total_Time_Of_D3_Search + Total_Time_Of_D3_Insert);
  printf("      TOTAL New    Node      : %llu\n", D3new_node);
  printf("      TOTAL Failed to Insert : %llu\n", D3failed_to_insert);
  printf("      TOTAL Alredy Exist     : %llu\n", D3already_exists);
  printf("      TOTAL Failed to Search : %llu\n", D3failed_Search);

  printf("         \n4 character\n");
  printf("         %.7f ns: Medium INSERT Time Per String\n", Total_Time_Of_D4_Insert / (f64)Tests_Limit / 15752961);
  printf("         %.7f ns: Medium SEARCH Time Per String\n", Total_Time_Of_D4_Search / (f64)Tests_Limit / 15752961);
  printf("         %.7f ms: TOTAL Time\n", Total_Time_Of_D4_Search + Total_Time_Of_D4_Insert);
  printf("      TOTAL New    Node      : %llu\n", D4new_node);
  printf("      TOTAL Failed to Insert : %llu\n", D4failed_to_insert);
  printf("      TOTAL Alredy Exist     : %llu\n", D4already_exists);
  printf("      TOTAL Failed to Search : %llu\n", D4failed_Search);

  printf("\n\n%.7f S: Total TESTS Time\n", Total_Time_Of_Tests);


  Arena_End(&arena);
}

/*
clang -O3 -o test.exe test.c -lwinmm
./test
-lwinmm
*/