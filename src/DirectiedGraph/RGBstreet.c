#include <stdlib.h>
#include <stdio.h>
#define min(a, b) (a > b ? b : a)

/* --------------- init --------------- */
void solved();

int main()
{
    solved();
    return 0;
}
void solved()
{
    int N;
    int answer[3] = {0, 0, 0};
    int R, G, B;
    int arr[3];
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d %d\n", &R, &G, &B);
        R += min(answer[1], answer[2]);
        B += min(answer[0], answer[2]);
        G += min(answer[0], answer[1]);
        answer[0] = R; answer[1] = B; answer[2] = G;
    }
    printf("%d", min(min(answer[0], answer[1]), answer[2]));
}


/* --------------- input example --------------- */
/*
3
26 40 83
49 60 57
13 89 99
*/

/*
3
1 100 100
100 1 100
100 100 1
*/

/*
3
1 100 100
100 100 100
1 100 100
*/

/*
6
30 19 5
64 77 64
15 19 97
4 71 57
90 86 84
93 32 91
*/

/*
8
71 39 44
32 83 55
51 37 63
89 29 100
83 58 11
65 13 15
47 25 29
60 66 19
*/