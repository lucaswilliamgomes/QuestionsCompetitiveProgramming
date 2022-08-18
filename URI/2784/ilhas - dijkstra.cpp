#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int N, M;

vector<pair<int, int>> graph[1010];

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

    fila.push(No(origem, 0));

    distancia[origem] = 0;

    while(!fila.empty()) {
        int vertice_atual = fila.top().vertice;

        fila.pop();

        if (visitados[vertice_atual]) continue;

        visitados[vertice_atual] = true;

        for(auto vizinho : graph[vertice_atual]) {
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


int main () {
    cin >> N >> M;

    int servidor;

    for (int i = 0; i < M; i++) {
        int u, v, c;

        cin >> u >> v >> c;

        graph[u].emplace_back(v, c);
        graph[v].emplace_back(u, c);
    }

    cin >> servidor;

    vector<int> distancias = Dijkstra(servidor);

    int min_ping = INT32_MAX;
    int max_ping = INT32_MIN;

    for (int i = 1; i <= N; i++) {
        if (i == servidor) continue;
        min_ping = min(min_ping, distancias[i]);
        max_ping = max(max_ping, distancias[i]);
    }   

    cout << max_ping - min_ping << endl;

    return 0;
}