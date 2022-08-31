#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUCKET_SIZE 100000

typedef struct node {
    char* data;
    struct node* next;
}NODE;

typedef struct bucket {
    NODE* head;
    int cnt;
}BUCKET;

BUCKET* hashTable = NULL;
int res = 0;

NODE* createNode(char* data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    char* buf = (char*)malloc(1001);
    strcpy(buf, data);
    newNode->data = buf;
    newNode->next = NULL;
    return newNode;
}

int hashFunc(int key)
{
    return key % BUCKET_SIZE;
}

int search(char* data, int idx)
{
    NODE* node = hashTable[idx].head;
    while (node != NULL)
    {
        if (strcmp(data, node->data) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

void add(char* data)
{
    NODE* newNode = createNode(data);
    int key = 0, i, idx;
    for (i = 0; data[i]; i++)
        key += data[i];
    idx = hashFunc(key);    
    if (hashTable[idx].cnt == 0)
    {
        hashTable[idx].head = newNode;
        res++;
    }
    else {
        if (search(data, idx))
            return;
        else {
            newNode->next = hashTable[idx].head;
            hashTable[idx].head = newNode;
            res++;
        }
    }
    hashTable[idx].cnt++;
}

void reset() 
{
    int i;
    NODE* node, * sub;
    for (i=0; i<BUCKET_SIZE; i++)
    {
        if (hashTable[i].cnt != 0)
        {
            node = hashTable[i].head;
            sub = node->next;
            while (sub != NULL)
            {
                free(node->data);
                free(node);
                node = sub;
                sub = node->next;
            }
            free(node->data);
            free(node);
            hashTable[i].cnt = 0;
        }
    }
}

int main(void)
{
    hashTable = (BUCKET*)malloc(BUCKET_SIZE * sizeof(BUCKET));
    int i, j, len;
    for (i = 0; i < BUCKET_SIZE; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].cnt = 0;
    }
    char* buf = (char*)malloc(1001);
    char* sub = (char*)malloc(1001);
    scanf("%s", buf);
    len = strlen(buf);
    for (i = 1; i <= len; i++)
    {
        for (j = 0; j < len - (i - 1); j++)
        {
            strncpy(sub, &buf[j], i);            
            sub[i] = '\0';
            add(sub);
        }
        reset();
    }
    printf("%d", res);
}