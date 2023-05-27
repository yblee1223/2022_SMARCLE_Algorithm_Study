#include <stdio.h>
#include <stdlib.h>

// init func
int cardSort(int *H);

int removeRoot(int *H);
void insertItem(int *H, int key);
void buildHeap(int *H);
void upHeap(int *H, int v);
void downHeap(int *H, int v);
void swap(int *a, int *b);
void printList(int* H);

int main()
{
    int N;
    
    scanf("%d", &N);

    int *H = (int*)calloc(N, sizeof(int));
    H[0] = N;
    for (int i = 1; i <= N; i++){
        scanf("%d", H + i);
    }
    buildHeap(H);
    printf("%d\n", cardSort(H));

    free(H);
    return 0;
}

int removeRoot(int *H)
{
    if (!H[0] && printf("0\n")) return 0;
    int root = H[1];
    H[1] = H[H[0]];
    H[H[0]--] = 0;
    downHeap(H, 1);
}
void insertItem(int *H, int key)
{
    H[++H[0]] = key;
    upHeap(H, H[0]);
}
void buildHeap(int *H)
{
    for (int i = H[0] / 2; i >= 1; i--){
        downHeap(H, i);
    }
}
void upHeap(int *H, int v)
{
    int parants = v / 2;
    if (v == 1) return;
    if (H[v] > H[parants]) return;
    swap(H + v, H + parants);
    upHeap(H, parants);
}
void downHeap(int *H, int v)
{
    int right_child = 2 * v;
    int left_child = 2 * v + 1;
    int smaller = left_child;
    if (!H[0] && left_child > H[0]) return;
    if (H[0] && H[right_child] && H[left_child] > H[right_child]) smaller = right_child;
    if (H[0] && H[v] < H[smaller] ) swap(H + v, H + smaller);
    downHeap(H, smaller);
    
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int cardSort(int *H)
{
    int output = 0;
    int first, second;
    while (1){
        first = removeRoot(H);
        second = removeRoot(H);
        output += first + second;
        if (!H[0]) break;
        insertItem(H, first + second);
    }
    return output;
}
void printList(int* H)
{
	for (int i = 1; i <= H[0]; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
/*
example input
3
10
20
40

*/