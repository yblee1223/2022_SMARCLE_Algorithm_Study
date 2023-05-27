#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
// struct 
typedef struct node{
    struct node * link;
    int elem;
}Node;
typedef struct stack{
    Node *top;
}Stack;

/* --- init func --- */
void init_stack(Stack *S);
Node* NewNode(int e);
void push(Stack *S, int e);
void pop(Stack *S)
int top(Stack *S);

int main()
{
    int N, P;
    int s_n, f_n; // string_num, fret_num
    int output = 0;
    Stack S[6];

    // init 
    for (int i=0; i<6; i++){
        init_stack(S+i);
    }

    // input
    scanf("%d %d\n", &N, &P);

    // func code
    for (int i=0; i<N; i++){

        scanf("%d %d\n", &s_n, &f_n); // input
        // case 1 : stack is null or top_elem < new_elem
        if (top(&S[s_n-1]) < f_n || top(&S[s_n-1]) == -1){
            push(&S[s_n-1], f_n);
            output++;
        }
        // case 2 : top_elem > new_elem
        // then pop infinity if (top_elem < new_elem)
        else{
            while (1){
                if (top(&S[s_n-1]) == f_n){
                    break;
                }
                else if (top(&S[s_n-1]) < f_n){
                    push(&S[s_n-1], f_n);
                    output++;
                    break;
                }
                else{
                    pop(&S[s_n-1]); // trash value
                    output++;
                }
            }
        }
    }
    printf("%d", output);
    return 0;
}

/* example

5 15
2 8
2 10
2 12
2 10
2 5


7 15
1 5
2 3
2 5
2 7
2 4
1 5
1 3

*/

void init_stack(Stack *S)
{
    S->top = NULL;
}
Node* NewNode(int e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->link = NULL;
    p->elem = e;
    return p;
}
void push(Stack *S, int e)
{
    Node *p = S->top;
    Node *q = NewNode(e);
    q->link = p;
    S->top = q;
}
void pop(Stack *S)
{
    Node *p = S->top;
    int q = p->elem;

    S->top = p->link;
    free(p);
    //return q;
}
int top(Stack *S)
{
    return S->top->elem;
}