#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int N, M;

vector<pair<int, pair<int,char>>> graph[MAXN];

struct No
{
    int vertice;
    int custo;

    No (int v = 0, int c = 0) {
        vertice = v;
        custo = c;
    }

    bool operator < (const No &a) const {
        return custo > a.custo;
    }
};


vector<int> Dijkstra (int origem) {
    vector<int> distancia(N + 1, INT32_MAX);
    vector<bool> visitados(N+1, false);

    priority_queue<No> fila;

    fila.push(No(origem, 0, -----------));

    distancia[origem] = 0;

    while(!fila.empty()) {
        int vertice_atual = fila.top().vertice;
        char letra_atual = fila.top().letra;

        fila.pop();

        if (visitados[vertice_atual]) continue;

        visitados[vertice_atual] = true;

        for(auto vizinho : graph[vertice_atual]) {
            if (vizinho.second.second < letra_atual) continue;
            int destino = vizinho.first;
            int custo_aresta = vizinho.second;

            if (distancia[destino] > distancia[vertice_atual] + custo_aresta) {
                distancia[destino] = distancia[vertice_atual] + custo_aresta;

                fila.push(No(destino, distancia[destino]));
            }
        }
    }

    return distancia;
}


int main(int argc, char **argv)
{
    optimize;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        pair<int,char> custo(1, l);

        graph[u].push_back({v, custo});
        graph[v].push_back({u, custo});
    }

    Dijkstra(1);

    
    

    return 0;
}

