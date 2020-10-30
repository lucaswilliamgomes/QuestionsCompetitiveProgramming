#include <bits/stdc++.h>

using namespace std;

vector <int> grafo[100005];
bool ans = true;

// Retorna o tamaanho da subarvore
int dfs (int u, int p = -1){

    int sz = 1, tam = -1;

    for (auto v : grafo[u]) if (v != p) {
        int x = dfs(v, u);
        sz += x;

        if (tam == -1) tam = x;

        if (tam != x){
            ans = false;
        }         
    }
    return sz;
}

int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        grafo[v].push_back(u);
    }

    dfs (0);

    cout << (ans ? "bem" : "mal") << endl;


    return 0;
}