#include <iostream>
using namespace std;

void printArray(int *a, int n){
    cout << "**** Printing array 1****" << endl;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << "[" << i << "]: " << *a << endl;
        a = a + 1;
    }
    
}

int main()
{
    int n = 15;
    int a[n] = {0};

    printArray(a, n);

    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0){
            a[i] = 2 * i;
        }else{
            a[i] = 3 * i;
        }
    }
    printArray(a, n);
}