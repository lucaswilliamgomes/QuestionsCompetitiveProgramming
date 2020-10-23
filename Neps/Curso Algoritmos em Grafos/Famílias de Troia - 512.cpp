#include <bits/stdc++.h>

using namespace std;

vector <int> grafo[50020];
int pai[50020];


void dfs (int u){

    for (auto v : grafo[u]){

        if (pai[v] == -1){
            pai[v] = pai[u];
            dfs(v);
        }
    }
}


int main () {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n;i++) pai[i]=-1;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);    
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){

        if (pai[i] == -1) {
            ans++;
            pai[i] = ans;
            dfs (i);
            
        }
    }

    cout << ans << endl;

    return 0;
}

