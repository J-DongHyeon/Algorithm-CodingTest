#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int row, col, i, j, plus_row=0, plus_col=0, res=99, sub;
    char * buf;
    char cmp[8][8] = {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                      {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                      {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                      {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                      {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                      {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                      {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                      {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};
    scanf("%d %d", &row, &col);
    char chess[row][col];
    buf = (char *)malloc(col+1);
    for (i=0; i<row; i++) 
    {
        scanf("%s", buf);
        strncpy(chess[i], buf, col);
    }
    while(8+plus_row <= row)
    {
        while(8+plus_col <= col)
        {
            sub = 0;
            for (i=0+plus_row; i<8+plus_row; i++)            
                for (j=0+plus_col; j<8+plus_col; j++)                
                    if (chess[i][j] != cmp[i-plus_row][j-plus_col]) sub++;      
            if (sub > 32) sub = 64 - sub;
            if (res > sub) res = sub;
            plus_col++;
        }
        plus_col = 0;
        plus_row++;
    }
    printf("%d", res);
}