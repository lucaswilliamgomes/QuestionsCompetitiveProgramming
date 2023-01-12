# Não resolvido

#include <bits/stdc++.h>
#define MAXNM 1010

using namespace std;

int n, m;
char graph[MAXNM][MAXNM];
bool visiteds[MAXNM][MAXNM];

vector<vector<char>> ans;

bool verifyConstraints(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and graph[i][j] != '#');
}

void dfs(int i, int j, vector<char> path) {
    if (visiteds[i][j]) return;
    visiteds[i][j] = true;
    if (verifyConstraints(i + 1, j)) {
        path.push_back('D');
        if (graph[i + 1][j] == 'B') {
            ans.push_back(path);
            return;
        }
        dfs(i + 1, j, path);
    }

    if (verifyConstraints(i - 1, j)) {
        path.push_back('U');
        if (graph[i - 1][j] == 'B') {
            ans.push_back(path);
            return;
        }
        dfs(i - 1, j, path);
    }

    if (verifyConstraints(i, j + 1)) {
        path.push_back('R');
        if (graph[i][j + 1] == 'B') {
            ans.push_back(path);
            return;
        }
        dfs(i, j + 1, path);
    }

    if (verifyConstraints(i, j - 1)) {
        path.push_back('L');
        if (graph[i][j - 1] == 'B') {
            ans.push_back(path);
            return;
        }
        dfs(i, j - 1, path);
    }
}

int main(int argc, char const *argv[])
{
    pair<int, int> start, end;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        for (int j = 0; j < m; j++) {
            if (aux[j] == 'A') start = {i, j};
            if (aux[j] == 'B') end = {i, j};
            graph[i][j] = aux[j];
        }
    }

    dfs(start.first, start.second, {});

    if (ans.size()) {
        cout << "YES" << endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans[1].size(); i++) {
            cout << ans[1][i];
        }
        cout << endl;
    }
    else cout << "NO" << endl;

    

    return 0;
}
