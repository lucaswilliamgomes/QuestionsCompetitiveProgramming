#include <bits/stdc++.h>

using namespace std;

int mapa[205][205], n, m;
bool visitados[205][205];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs (int i, int j){
    int sz = 1;

    visitados[i][j] = true;

    for (int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];

        if (x < 1 or x > n or y < 1 or y > m or visitados[x][y] or mapa[i][j] != mapa[x][y]) continue;
        sz += dfs(x, y);
    }

    return sz;
}

int main () {
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> mapa[i][j];
        }
    }

    int ans = 100000000;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!visitados[i][j]){
                ans = min (ans, dfs (i, j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}