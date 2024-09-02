#include <iostream>
using namespace std;
int main()
{
    int i, j, k = 0;
    int N = 5;

    //O(n*n)
    for (i = N / 2; i <= N; i++)
    {
        for (j = 2; j <= N; j = j * 2)
        {
            k = k + N / 2;
        }
    }

    cout << k << endl;
    return 0;
}