#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graphType{
    int ** lst;
    int l;
    int h;
}GraphType;

/* ---------- init ---------- */
void initGraph(GraphType * G);
void add(GraphType * G, int x, int y);
void DPS();
void printGraph(GraphType * G);
int solved();

int T;
int M, N, K;// width, height, number

int main()
{
    int answer;
    scanf("%d\n", &T);
    for (int i = 0; i < T; i++){
        answer = solved();
        printf("%d\n", answer);
    } 
}
int solved()
{
    int x, y; // column, row
    int answer = 0;

    /* --- input --- */

    scanf("%d %d %d\n", &M, &N, &K);
    GraphType G;
    initGraph(&G);

    for (int i = 0; i < K; i++){
        scanf("%d %d\n", &x, &y);
        add(&G, x, y);
    }
    printGraph(&G);

    /* --- output --- */

    return answer;
}

void initGraph(GraphType * G)
{
    G->l = M; 
    G->h = N;
    G->lst = (int**)malloc(sizeof(int*) * (G->h + 1));
    for (int i = 0; i < G->h + 1; i++){
        (G->lst)[i] = (int*)calloc(1, sizeof(int) * (G->l + 1));
    }
}
void add(GraphType * G, int x, int y)
{
    G->lst[y][x] = 1;
}
void printGraph(GraphType * G)
{
    printf("\n/* ----- graph ----- */\n");
    for (int i = 0; i < G->h; i++){
        for (int j = 0; j < G->l; j++){
            printf("%d", G->lst[i][j]);
        }
        printf("\n");
    }
}

/* ---------- input example ---------- */
/*
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
*/

/*
1
5 3 6
0 2
1 2
2 2
3 2
4 2
4 0
*/