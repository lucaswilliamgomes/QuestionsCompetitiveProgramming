#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int N, ans = 0;
bool visitados[2005];

void dfs(int v) {
    visited[v] = true;
    for (auto u: adj[v]) {
        dfs(u);
    }
}



int main () {
    cin >> N;

    for (int i = 1; i <= n; i++){
        visitados[i] = -1;
    }






    return 0;
}