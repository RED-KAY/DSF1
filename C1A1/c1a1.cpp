#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int N = 5;
    //N * (N + N-1 + N-2 + N-3 + N-4)
    //O(n*n)
    for (int i = 0; i < N; i++) { 
        for (int j = N; j > i; j--) {
            sum = sum + i + j;
        }
    }
    cout << "For N = " << N << " sum = " << sum << '\n';
	return 0;
}