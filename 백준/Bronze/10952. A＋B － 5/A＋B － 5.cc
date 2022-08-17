#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int a, b, i;
    vector<int> vec;
    while(true)
    {
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0) break;
        vec.push_back(a+b);
    }
    for(i=0; i<vec.size(); i++)
    {
        cout << vec[i] << "\n";
    }
}