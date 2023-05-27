#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct graphType{
    int **v;
    int n;
}GraphType;

/* ---------- init func ---------- */
void initGraph(GraphType * G);
void add(GraphType * G, int v1, int v2);
void virus(GraphType * G);
void printGraph(GraphType * G);
void freeGraph(GraphType * G);
void printVirusCom();
void DFS(GraphType * G, int x);

/* ---------- global variable ---------- */
int COM_COUNT;
GraphType G;
int * visited;

/* ---------- main func ---------- */
int main()
{
    int N;
    int v1, v2;
    int virus;
    

    // input
    scanf("%d\n", &COM_COUNT);
    initGraph(&G);
    visited = (int*)calloc(1, sizeof(int) * (COM_COUNT + 1));

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &v1, &v2);
        add(&G, v1, v2);
    }

    // culc
    DFS(&G, 1);

    // output
    printVirusCom();
    //printGraph(&G);
    //freeGraph(&G);
    return 0;
}
/* ---------- function ---------- */
void initGraph(GraphType * G)
{
    G->v = (int**)malloc(sizeof(int) * (COM_COUNT + 1));
    for (int i = 0; i <= COM_COUNT; i++){
        (G->v)[i] = (int*)calloc(1, sizeof(int) * COM_COUNT);
    }
    G->n = COM_COUNT;
}
void add(GraphType * G, int v1, int v2)
{
    G->v[v1][v2] = 1;
    G->v[v2][v1] = 1;
}
void DFS(GraphType * G, int x)
{
    visited[x] = 1;
    for (int i = 1; i <= COM_COUNT; i++){
        if (i == x) {
            continue;
        }
        if (G->v[x][i]) {
            if (!visited[i]) {
                DFS(G, i);
            }
        }
    }
    return;
}
void printGraph(GraphType * G)
{
    printf("/* ----- graph ----- */\n");
    for (int i = 1; i <= COM_COUNT; i++){
        for (int j = 1; j <= COM_COUNT; j++){
            printf(" %d", G->v[i][j]);
        }
        printf("\n");
    }
}
// void freeGraph(GraphType * G)
// {
//     for (int i = 0; i <= COM_COUNT; i++){
//         free((G->v)[i]);
//     }
//     free(G->v);
// }
void printVirusCom()
{
    int sum = 0;
    for (int i = 2; i <= COM_COUNT; i++){
        sum += visited[i];
    }
    printf("%d\n", sum);
}
/* ---------- input example ---------- */
/*
8
6
1 8
2 3
1 5
5 2
5 6
4 7
*/