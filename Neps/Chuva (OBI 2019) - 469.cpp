#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, M;

    cin >> N >> M;
    
    char matrix [1010][1010];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (matrix[i][j] == '.'){
                if ((i > 0 && matrix[i-1][j] == 'o') or 
                (i < N - 1 && j > 0 && matrix[i][j-1] == 'o' and matrix[i+1][j-1] == '#') or 
                (i < N - 1 && j < M - 1 && matrix[i][j+1] == 'o' and matrix[i+1][j+1] == '#')) {
                    matrix[i][j] = 'o';

                    if (j > 0)
                        j-=2;
                    
                }
            }
        }
    }


    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}