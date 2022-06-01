// tle
// Assuntos para resolver:
//      binary lifting
//      LCA
#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

struct Aresta
{
    int u, v, c;
    Aresta(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}

    bool operator < (const Aresta &a) {
        return c < a.c;
    }
};

vector<Aresta> graph;
int pai[MAXN];

int find(int x) {
    if (x != pai[x]) 
        return pai[x] = find(pai[x]);
    else 
        return x;
}

void join(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        pai[u] = v;
    }
}

ll kruskal(int u, int v) {
    ll ans = 0;
    for (auto aresta: graph) {
        if (!(aresta.u == u && aresta.v == v)) {
            if (find(aresta.u) != find(aresta.v)) {
                ans += aresta.c;
                join(aresta.u, aresta.v);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, m;

    cin >> n >> m;
    vector<Aresta> copy;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.emplace_back(u, v, c);
        copy.emplace_back(u, v, c);
    }

    sort(graph.begin(), graph.end());

    for (auto aresta: copy) {
        for (int i = 0; i <= n; i++) {
            pai[i] = i;
        }
        int cInicial = 0;
        if (find(aresta.u) != find(aresta.v)) {
            cInicial += aresta.c;
            join(aresta.u, aresta.v);
        }
        cout << cInicial + kruskal(aresta.u, aresta.v) << endl;
    }

    return 0;
}
