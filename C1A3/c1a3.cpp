#include <iostream>
using namespace std;
int main()
{
    int N = 5;
    int a = 0, i = N;

    //O(n)
    while (i > 0)
    {
        a += i;
        i /= 2;
    }

    return 0;
}