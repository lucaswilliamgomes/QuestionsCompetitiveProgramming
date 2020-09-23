#include <bits/stdc++.h>

using namespace std;

vector <int> grafo[100];

bool visitados[100];



int dfs (int u) {
    int ans = 0;
    // Processa o U
    visitados[u] = true;

    for (int v : grafo[u]){
        if (visitados[v] == false){
            ans += 2 + dfs(v);
        }

    }

    return ans;
}


int main () {
    int t;
    cin >> t;

    while (t--){
        int n, ver, a;
        cin >> n >> ver >> a;

        for (int i = 0; i <= ver; i++){
            grafo[i].clear();
            visitados[i] = false;
        }

        int u, v;
        for (int i = 0; i < a; i++){
            cin >> u >> v;
            grafo[u].push_back(v);
            grafo[v].push_back(u);

        }

        cout << dfs(n) << endl;
    }


    return 0;
}