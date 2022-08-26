#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUCKET_SIZE 1000

typedef struct node {
    int num;
    char* name;
    struct node* next;
}NODE;

typedef struct {
    NODE* head;
    int cnt;
}BUCKET;

BUCKET* hashTable = NULL;

NODE* createNode(int num, char* value)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE));    
    newNode->num = num;
    newNode->name = value;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key)
{
    return key%BUCKET_SIZE;
}

void add(int num, char* value)
{
    int i, key = 0;
    int hashIdx;
    for (i=0; value[i]; i++)
        key += value[i];
    NODE* newNode = createNode(num, value);
    hashIdx = hashFunction(key);    
    if (hashTable[hashIdx].cnt == 0)
    {
        hashTable[hashIdx].head = newNode;
    } else {
        newNode->next = hashTable[hashIdx].head;
        hashTable[hashIdx].head = newNode;
    }
    hashTable[hashIdx].cnt++;
}

void search(char* value)
{
    NODE* node;
    int i, key = 0;
    int hashIdx;
    for (i=0; value[i]; i++)
        key += value[i];
    hashIdx = hashFunction(key);
    node = hashTable[hashIdx].head;
    while (node != NULL)
    {
        if (strcmp(value, node->name) == 0)
        {
            printf("%d\n", node->num);
            return;
        }
        node = node->next;
    }
}

int main(void)
{
    int n, m, i;
    char** buf = (char**) malloc(100000 * sizeof(char*));
    char* sub = (char*) malloc(21);
    hashTable = (BUCKET*) malloc(BUCKET_SIZE * sizeof(BUCKET));
    for (i=0; i<BUCKET_SIZE; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].cnt = 0;
    }
    scanf("%d %d", &n, &m);
    for (i=1; i<=n; i++)
    {
        buf[i-1] = (char*) malloc(21);
        scanf("%s", buf[i-1]);
        add(i, buf[i-1]);
    }
    for (i=0; i<m; i++)
    {
        scanf("%s", sub);
        if (isdigit(sub[0]))
        {
            printf("%s\n", buf[atoi(sub) - 1]);
        } else
            search(sub);
    }
}
