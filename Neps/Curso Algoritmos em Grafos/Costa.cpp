#include <bits/stdc++.h>

using namespace std;

int main () {
    int M, N;
    cin >> M >> N;

    char mapa[M+2][N+2];

    for (int i = 0; i < M+2; i++){
        for (int j = 0; j < N+2; j++){
            mapa[i][j] = '.';
        }
    }

    int ans = 0;

    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            cin >> mapa[i][j];
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (mapa[i][j] == '#'){
            
                if (mapa[i+1][j] == '.' || mapa[i][j+1] == '.' || mapa[i-1][j] == '.' || mapa[i][j-1] == '.'){
                    ans++;
                } 
            }
        }
    }

    cout << ans << endl;

    return 0;
}