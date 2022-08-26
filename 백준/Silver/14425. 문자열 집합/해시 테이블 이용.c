#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    char* value;
    struct node* next;
} NODE;

typedef struct bucket
{
    NODE* head;
    int cnt;
} BUCKET;

int BUCKET_SIZE = 1000;
BUCKET* hashTable = NULL;
int res = 0;

NODE* createNode(int key, char* value)
{
    NODE* newNode;
    char* buf = (char*)malloc(501);
    strcpy(buf, value);
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = key;
    newNode->value = buf;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key)
{
    return key % BUCKET_SIZE;
}

void add(int key, char* value)
{
    int hashIndex = hashFunction(key);
    NODE* newNode = createNode(key, value);
    if (hashTable[hashIndex].cnt == 0)
    {
        hashTable[hashIndex].head = newNode;
    }
    else {
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
    }
    hashTable[hashIndex].cnt++;
}

void search(int key, char* value)
{
    int hashIndex = hashFunction(key);
    NODE* node = hashTable[hashIndex].head;   
    while (node != NULL)
    {
        if (node->key == key && strcmp(value, node->value) == 0)
        {
                res++;
                return;
        }
        node = node->next;
    }    
}

int main(void)
{
    int num, cmp, i, j, key;
    char* buf = (char*)malloc(501);
    hashTable = (BUCKET*)malloc(BUCKET_SIZE * sizeof(BUCKET));
    for (i = 0; i < 1000; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].cnt = 0;
    }    
    scanf("%d %d", &num, &cmp);
    for (i = 0; i < num; i++)
    {
        key = 0;
        scanf("%s", buf);
        for (j = 0; buf[j]; j++)
            key += buf[j];
        add(key, buf);
    }
    for (i = 0; i < cmp; i++)
    {
        key = 0;
        scanf("%s", buf);
        for (j = 0; buf[j]; j++)
            key += buf[j];
        search(key, buf);
    }
    printf("%d", res);
}
