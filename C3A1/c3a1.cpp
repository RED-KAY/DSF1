#include <iostream>
using namespace std;

#define M 3
#define N 4

char arr[M][N] = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
};

string outputPath = "";

int check(int m, int n, string s, int index, char dir, char lastCellDir){
    if(m >= M) return -1;
    if(n >= N) return -1;

    if(dir != '\0'){
        if(dir == 'N' && lastCellDir == 'S') return -1;
        else if(dir == 'S' && lastCellDir == 'N') return -1;
        else if(dir == 'E' && lastCellDir == 'W') return -1;
        else if(dir == 'W' && lastCellDir == 'E') return -1;
    }

    char c = arr[m][n];
    char k = s[index];

    if(c != k){
        
        return -1;
    }else{
        index++;
        outputPath.append(1, dir);
        if(index >= s.size()){
            cout << "true" << endl;
            cout << "path: " << outputPath << endl;
            return 1;
        }
        check(m-1, n, s, index, 'N', dir);
        check(m, n+1, s, index, 'E', dir);
        check(m+1, n, s, index, 'S', dir);
        check(m, n-1, s, index, 'W', dir);
        
        return -1;
    }
    return -1;
}


//if match
//check(m-1, n, s, i, 1)
//check(m, n+1, v, 2)
//check(m+1, n, v, -1)
//check(m, n-1, v, -2)

//1. out of bounds m/n
//2. not match
//3. if lastDir != currentDir

//ees

int main() {

    cout << "Hello World " << endl;
    string s;
    cin >> s;
    cout << "string is " << s << endl;

    char s1 = s[0];
    int r = -1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            r = check(i, j, s, 0, '\0', '\0');
            cout << arr[i][j] << " - " << r << endl;
            if(r == 1){
                
                break;
            }
            else if(r == -1) outputPath.clear();
            //outputPath.clear();
        }
        if(r == 1) break;
        else if( r == -1) outputPath.clear();
    }
    
	return 0;
}