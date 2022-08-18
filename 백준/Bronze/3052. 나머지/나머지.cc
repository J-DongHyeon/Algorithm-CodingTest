#include <stdio.h>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> vec;
    int a, i, j;
    for(i=0; i<10; i++)
    {
        scanf("%d", &a);
        a %= 42;
        for(j=0; j<vec.size(); j++)
        {
            if (a == vec[j]) break;
        }
        if (j == vec.size()) vec.push_back(a);
    }
    
    printf("%d", vec.size());
}