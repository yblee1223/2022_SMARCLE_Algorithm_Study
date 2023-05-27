#include <stdio.h>
#include <stdlib.h>

/* <introduction>
1. input variable
2. insert max_heap & min_heap, and compare Max & min & middle
3. output center
*/

// init func
void insertItem(int* H, int key);
int removeItem(int* H);
void printHeap(int* H);

void upHeap(int* H, int v);
void downHeap(int* H, int v);
void swap(int* a, int* b);



int main()
{
    // init variable
    int* Max_H; // Max Heap Smaller
    int* Min_H; // Min Heap Bigger

    // 0 index is Heap counter

    int N;
    int x; // input variable
    int middle; // middle output

    scanf("%d", &N);
    // dynamic allacation
    Max_H = (int*)calloc(N, sizeof(int));
    Min_H = (int*)calloc(N, sizeof(int));
    Max_H[0] = 0;
    Min_H[0] = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        // max heap
        if (i == 0) {
            middle = x;
        }
        else if (x >= middle) {
            insertItem(Min_H, -1 * x);
        }
        else if (x < middle) {
            insertItem(Max_H, x);
        }
        while (!(Min_H[0] == Max_H[0] + 1 || Min_H[0] == Max_H[0])) {
            if (Min_H[0] > Max_H[0]) {
                insertItem(Max_H, middle);
                middle = -1 * removeItem(Min_H);
            }
            else if (Min_H[0] < Max_H[0]) {
                insertItem(Min_H, -1 * middle);
                middle = removeItem(Max_H);
            }
            else {// same MaxH count & MinH count
                break;
            }
        }
        /*
        printf("Min Heap:");
        printHeap(Min_H);
        printf("center: %d\n", middle);
        printf("Max Heap:");
        printHeap(Max_H);
        printf("\n");
        */

        printf("%d\n", middle);
    }
    return 0;
}

// Function
void insertItem(int* H, int key)
{
    // exception over heap range
    //if (H[0] > 99) return;
    H[++H[0]] = key;
    //printf("0\n");
    upHeap(H, H[0]);
}
int removeItem(int* H)
{
    int root;
    // exception blank heap
    //if (H[0] <= 0) return;
    //printf("%d\n", H[1]);
    root = H[1];
    H[1] = H[H[0]];
    H[H[0]] = 0;
    H[0]--;
    downHeap(H, 1);
    return root;
}

void upHeap(int* H, int v)
{
    int parent = v / 2;
    if (v == 1) return;
    else if (H[v] < H[parent]) return;
    swap(H + v, H + parent);
    upHeap(H, parent);
}
void downHeap(int* H, int v)
{
    int left_child = 2 * v;
    int right_child = 2 * v + 1;

    if (left_child > H[0]) {
        return; // no leaf_node
    }

    int larger = left_child;
    
    if (H[0] != left_child && H[right_child] > H[larger]) {
        larger = right_child;
    }
    if (H[v] < H[larger]) {
        swap(H + v, H + larger);
    }
    downHeap(H, larger);
}
void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printHeap(int* H)
{
    for (int i = 1; i <= H[0]; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

// Example
/*
7
1
5
2
10
-99
7
5


5
1
5
1
5
1
5
1

*/