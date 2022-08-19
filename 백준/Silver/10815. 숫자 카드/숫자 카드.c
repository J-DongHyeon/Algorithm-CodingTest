#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int num1 = *(int*) a;
    int num2 = *(int*) b;
    if (num1 > num2) return 1;
    else if (num1 < num2) return -1;
    else return 0;
}

int main(void)
{
    int num, i, cmp;
    scanf("%d", &num);
    int card[num];
    for (i=0; i<num; i++) scanf("%d", &card[i]);
    scanf("%d", &cmp);
    int card_cmp[cmp];
    for (i=0; i<cmp; i++) scanf("%d", &card_cmp[i]);
    qsort(card, sizeof(card) / sizeof(card[0]), sizeof(int), compare);
    for (i=0; i<cmp; i++)
    {
        int low = 0, high = num-1, mid, ck = 0;
        while (high >= low)
        {
            mid = (low + high) / 2;
            if (card_cmp[i] == card[mid])
            {
                card_cmp[i] = 1;
                ck = 1;
                break;
            } else if (card_cmp[i] > card[mid]) low = mid + 1;
            else high = mid - 1;
        }
        if (ck == 0) card_cmp[i] = 0;
    }
    for (i=0; i<cmp; i++) printf("%d ", card_cmp[i]);
}