#include <bits/stdc++.h>
#define MAXNM 1005

using namespace std;

int n, m, ans = 0;
char build[MAXNM][MAXNM];
bool visiteds[MAXNM][MAXNM];

bool verifyConstraints(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and build[i][j] == '.');
}

void dfs(int i, int j) {
    if (visiteds[i][j]) return;
    visiteds[i][j] = true;

    if (verifyConstraints(i + 1, j) && !visiteds[i + 1][j]) dfs(i + 1, j);
    if (verifyConstraints(i - 1, j) && !visiteds[i - 1][j]) dfs(i - 1, j); 
    if (verifyConstraints(i, j + 1) && !visiteds[i][j + 1]) dfs(i, j + 1); 
    if (verifyConstraints(i, j - 1) && !visiteds[i][j - 1]) dfs(i, j - 1); 
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        for (int j = 0; j < m; j++) {
            build[i][j] = aux[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (build[i][j] == '.' && !visiteds[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
