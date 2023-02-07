#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int N, M, u, v, c;

struct Aresta
{
    int u, v, c;
    Aresta(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}

    bool operator < (const Aresta &a) {
        return c < a.c;
    }
};

vector<Aresta> grafo;
int pai[MAXN];

void init() {
    for (int i = 0; i < N; i++) {
        pai[i] = i;
    }
}

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        pai[u] = v;
    }
}

int kruskal(int a = -1, int b = -1) {
    sort(grafo.begin(), grafo.end());

    int ans = 0;

    for (auto aresta: grafo) {
        if (aresta.u == a && aresta.v == b || 
            aresta.u == b && aresta.v == a ) continue;
        if (find(aresta.u) != find(aresta.v)) {
            ans += aresta.c;
            join(aresta.u, aresta.v);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{   
    cin >> N >> M;

    init();

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        arestas.push_back({u, v});
        grafo.push_back(Aresta(u, v, c));
    }

    int min_ = kruskal();

    cout << min_ << endl;

    for (int i = 0; i < M; i++) {
        init();
        cout << kruskal(arestas[i].first, arestas[i].second) << endl;
        // if (kruskal(arestas[i].first, arestas[i].second) == min_) {
        //     cout << "at least one" << endl;
        // } else {
        //     cout << "any" << endl;
        // }
    }

    return 0;
}
