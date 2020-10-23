
// SEM GRAFOS
#include <bits/stdc++.h>

using namespace std;

int mapa[1125][1125];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main () {
    int n, m, x, y;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
            cin >> mapa[i][j];
            if (mapa[i][j] == 3){
                x = i;
                y = j;
            }
        }
    }

    int ans = 1;

    while (mapa[x][y] != 2) {
        for (int i = 0; i < 4; i++){
            if (mapa[x + dx[i]][y + dy[i]]){
                ans++;
                mapa[x][y] = 0;
                x += dx[i];
                y += dy[i];
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}