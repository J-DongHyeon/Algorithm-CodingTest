#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 100000

typedef struct node {
    int card;
    int num;
    struct node* next;
}NODE;

typedef struct bucket {
    NODE* head;
    int cnt;
}BUCKET;

BUCKET* hashTable = NULL;

NODE* createNode(int card)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->card = card;
    newNode->num = 1;
    newNode->next = NULL;
    return newNode;
}

int hashFunc(int key)
{
    return key%BUCKET_SIZE;
}

int search (int card)
{
    int idx;
    if (card >= 0)
        idx = hashFunc(card);
    else
        idx = hashFunc(-1 * card);
    
    NODE* node = hashTable[idx].head;
    while(node != NULL)
    {
        if (node->card == card)
            return node->num;
        node = node->next;
    }
    return 0;
}

void add (int card)
{
    NODE* newNode = createNode(card);
    int idx;
    if (card >= 0)
        idx = hashFunc(card);
    else
        idx = hashFunc(-1 * card);    
    if (hashTable[idx].cnt == 0)
    {
        hashTable[idx].head = newNode;
    } else {
        NODE* node = hashTable[idx].head;
        while (node != NULL) 
        {
            if (node->card == card)
            {
                node->num++;
                return;
            }
            node = node->next;
        }        
        newNode->next = hashTable[idx].head;
        hashTable[idx].head = newNode;
    }
    hashTable[idx].cnt++;
}


int main(void)
{
    hashTable = (BUCKET*) malloc(BUCKET_SIZE * sizeof(BUCKET));
    int n, m, i, buf;
    for (i=0; i<BUCKET_SIZE; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].cnt = 0;
    }
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &buf);
        add(buf);
    }
    scanf("%d", &m);
    int* res = (int*) malloc(m * sizeof(int));
    for (i=0; i<m; i++)
    {
        scanf("%d", &buf);
        res[i] = search(buf);
    }
    for (i=0; i<m; i++)
        printf("%d ", res[i]);
}