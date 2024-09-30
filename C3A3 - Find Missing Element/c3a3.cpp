#include <iostream>
using namespace std;

int main(){
    int N = 4;
    int A[N] = {1,2,3,5};

    int n = 5;
    bool swapped = false;
    
    //Sort
    for (int i = 0; i < N-1; i++)
    {
        swapped = false;
        for(int j=0; j<N-i-1; j++){
            if(A[i] > A[j+1]){
                int temp = A[i];
                A[i] = A[j+1];
                A[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(A[i] != i+1){
            cout << i+1 << endl;
            break;
        }
    }
    

    return 0;
}