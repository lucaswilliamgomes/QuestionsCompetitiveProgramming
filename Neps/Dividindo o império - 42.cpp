#include <bits/stdc++.h>

using namespace std;

vector <int> grafo[200000];

int N;
int ans = INFINITY;


int dfs (int u, int pai){

    int pra_baixo, sz = 1;

    for (int v : grafo[u]){
        if(v != pai){
            pra_baixo = dfs(v, u);

            int filho1 = pra_baixo;
            int filho2 = N - filho1;

            ans = min(ans, abs(filho1-filho2));

            sz += pra_baixo;

        }
    }

    return sz;

}

int main (){

    int u, v;

    cin >> N;

    for (int i = 1; i < N; i++){

        cin >> u >> v;

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    dfs (1, -1);

    cout << ans << endl;

    return 0;
}