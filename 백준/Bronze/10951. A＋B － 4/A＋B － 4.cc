#include <stdio.h>
#include <vector>
using namespace std;

int main(void)
{
    int a, b, i;
    vector<int> vec;
    
    while(true)
    {
        if (scanf("%d", &a) == EOF) break;
        scanf(" %d", &b);
        vec.push_back(a+b);
    }
    for(i=0; i<vec.size(); i++) printf("%d\n", vec[i]);
}
