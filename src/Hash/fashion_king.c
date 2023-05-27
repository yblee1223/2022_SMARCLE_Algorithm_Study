#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*--------------- Introduction ---------------*/
// 문제: 혜빈이의 옷장에 있는 옷의 조합을 만들어서 알몸으로 밖에 돌아다니기 전까지 입을 수 있는 옷의 조합 수
// 구현: hash table (with str)
// 알고리즘: 


/*--------------- structure ---------------*/
typedef struct node{
    char key[20];
    char value[20];
    struct node * next;
}Node;
typedef struct bucket{
    Node * head;
    int count;
}Bucket;



/*--------------- init func ---------------*/
Node* createNode(char key[], char value[]);
int hashFunction(char key[]);
void add(char value[]);
void remove_key(char key[]);
void search(char key[]);
void display();


/*--------------- global variable ---------------*/
int TEST_CASE;
Bucket* hashTable;

/*--------------- main func ---------------*/
int main()
{
    int C_COUNT;
    char name[20], tag[20]

    /* input & save */
    scanf("%d", &BUCKET_SIZE);

    hashTable = (Bucket*)calloc(1, TEST_CASE * sizeof(Bucket));

    for (int i = 0; i < BUCKET_SIZE; i++){
        scanf("%d\n", &C_COUNT);
        hashTable[i].count = 0;
        for(int j = 0; j < C_COUNT; j++){
            scanf("%s %s", name, tag);
            getchar();
            add(tag, name);
        }
    }

    

    
    return 0;
}
/*--------------- function ---------------*/
int hashFunction(char key[])
{
    int output = 0;
    len = strlen(key);
    for (int i = 0; i < len; i++){
        output += key[i] * pow(33, i);
    }
    output %= TEST_CASE;
    return output;
}
Node* createNode(int key, int value)
{
    Node * newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void add(char key[], char value[])
{
    // 어떤 버켓에 추가할지 인덱스 계산
    int hashIndex = hashFunction(key);
    Node* newNode = createNode(key, value);

    // 처음 삽입할때
    if (hashTable[hashIndex].count == 0){
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode;
    }
    // 버킷에 이미 누군가 있을때
    else{
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
}

/*--------------- input example ---------------*/
/*
2
3
hat headgear
sunglasses eyewear
turban headgear
3
mask face
sunglasses face
makeup face
*/