#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

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

int kruskal() {
    sort(grafo.begin(), grafo.end());

    int ans = 0;

    for (auto aresta: grafo) {
        if (find(aresta.u) != find(aresta.v)) {
            ans += aresta.c;
            join(aresta.u, aresta.v);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{   
    int N, M, u, v, c;

    while((cin >> N >> M) && (N+M)) {
        grafo.clear();
        int soma = 0;

        for (int i = 0; i < N; i++) {
            pai[i] = i;
        }

        while(M--) {
            cin >> u >> v >> c;
            soma += c;
            grafo.emplace_back(u,v,c);
        }

        cout << soma - kruskal() << endl;
    }
    
    
    return 0;
}
