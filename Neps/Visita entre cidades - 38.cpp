#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020


using namespace std;

vector <pair <int, int>> grafo[MAXN];
int N, O, D, P, Q, C;
int pai[MAXN], peso[MAXN];

void dfs (int u, int p) {
    for (auto it : grafo[u]){
        int v, c;

        v = it.first;
        c = it.second;

        if (p != v) {
            
            pai[v] = u;
            peso[v] = c;

            dfs(v, u);
        }
    }

}

int main(int argc, char const *argv[]){
    

    cin >> N >> O >> D;

    for (int i = 1; i < N; i++){
        cin >> P >> Q >> C;


        grafo[P].emplace_back (Q, C);
        grafo[Q].emplace_back (P, C);
    }

    dfs (O, -1);

    int ans = 0;

    while (D != O){
        ans += peso[D];
        D = pai[D];
    }
    
    cout << ans << endl;
    return 0;
}
