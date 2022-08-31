#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
}NODE;

typedef struct bucket {
    NODE* head;
    int cnt;
}BUCKET;

BUCKET* hashTable = NULL;
int res = 0;

NODE* createNode(int data)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int hashFunc(int key)
{
    return key%BUCKET_SIZE;
}

void add(int data)
{
    NODE* newNode = createNode(data);
    int idx = hashFunc(data);
    if (hashTable[idx].cnt == 0)
        hashTable[idx].head = newNode;
    else {
        newNode->next = hashTable[idx].head;
        hashTable[idx].head = newNode;
    }
    hashTable[idx].cnt++;
}

void search(int data)
{
    int idx = hashFunc(data);
    NODE* node = hashTable[idx].head;
    while (node != NULL)
    {
        if (node->data == data)
        {
            res++;
            return;
        }
        node = node->next;
    }
}

int main(void)
{
    hashTable = (BUCKET*) malloc(BUCKET_SIZE * sizeof(BUCKET));
    int a, b, i, buf;
    scanf("%d %d", &a, &b);
    for (i=0; i<BUCKET_SIZE; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].cnt = 0;
    }
    for (i=0; i<a; i++)
    {
        scanf("%d", &buf);
        add(buf);
    }
    for (i=0; i<b; i++)
    {
        scanf("%d", &buf);
        search(buf);
    }
    printf("%d", (a-res) + (b-res));
}