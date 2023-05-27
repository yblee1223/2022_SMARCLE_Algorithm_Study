/*-------------------------------------- INTRODUCTION ----------------------------------*/
// The world-famous thief Sang-deok decides to rob a jewelry store.
//
// There are a total of N jewels in Sangdeoki's hair jewelry store. 
// Each gem has a weight Mi and a price Vi. Sangdeok has K bags, and the maximum weight each bag can hold is Ci. 
// A bag can only contain one jewel at most.
//
// Write a program to find the maximum price for a jewel that Sangdeok can steal.
//
// N and K are given in the first line. (1 ≤ N, K ≤ 300,000)
// The next N lines give information Mi and Vi for each gem. (0 ≤ Mi, Vi ≤ 1,000,000)
// The next K rows are given the maximum weight Ci the bag can hold. (1 ≤ Ci ≤ 100,000,000)
// All numbers are positive integers.
/*-------------------------------------- SEQUENCE --------------------------------------*/
// 1. input N, K
// 2. input M_i, V_i if M_i is <= K in List
// 3. sorting (mergesort, HeapSort)
/*--------------------------------------------------------------------------------------*/



/*-------------------------------------- CODE ------------------------------------------*/
 #include <stdio.h>
 #include <stdlib.h>

/*-------------------------------------- init func -------------------------------------*/
void addLast();
/*-------------------------------------- func ------------------------------------------*/

 int main()
 {
    int N, K;
    int M, V;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &M, &V);
        if (M < K){
            
        }

    }
    return 0;
 }
 
/*-------------------------------------- func ------------------------------------------*/
 
 
/*-------------------------------------- input example ----------------------------------*/

// example 1
/*
2 1
5 10
100 100
11
*/
// example 2
/*
3 2
1 65
5 23
2 99
10
2
*/