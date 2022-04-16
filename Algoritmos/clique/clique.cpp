#include <bits/stdc++.h>
using namespace std;
int cont = 0;
// Tamanho máximo do grafo
const int MAX = 100;

// Armazena os vértices
int store[MAX], n;

// Grafo
int graph[MAX][MAX];

// Graus dos vertices
int d[MAX];

set<int> cliques;

// Função para verificar se dado um conjunto de
// vértices no array store é um clique ou não
bool is_clique(int b)
{
    // Para todos os conjutos de vertices
    for (int i = 1; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
            // Se algum vertice estiver faltando
            if (graph[store[i]][store[j]] == 0)
                return false;
        cliques.insert(store[i]);
    }
    return true;
}

// Função para encontrar todos os tamanhos
// de cliques máximos
int maxCliques(int i, int l)
{
    // Tamanho do clique máximo até agora
    int max_ = 0;

    // Verifica se algum vértice i+1
    // pode ser inserido
    for (int j = i + 1; j <= n; j++)  // Para cada aresta eu vou tentar encontrar o maior subgrafo clique comecando dessa aresta
    {
        cont++;
        // Adiciono o vertice no store
        store[l] = j;

        // Se o grafo não for um clique de tamanho k então
        // não pode ser um clique adicionando outra aresta (k+1)
        if (is_clique(l + 1))
        {
            // atualiza o max
            max_ = max(max_, l);

            // Verifique se outra aresta pode ser adicionada
            max_ = max(max_, maxCliques(j, l + 1));
        } else {
            cliques.clear();
        }
    }
    return max_;
}

int main()
{
    int edges[][2] = {
        {1, 2}, {1, 3}, {1, 4}, {1, 5}, 
        {2, 3},{2,4}, {2, 5},
        {3, 4}, {3, 5}
        };
    int size = sizeof(edges) / sizeof(edges[0]);
    n = 5;

    for (int i = 0; i < size; i++)
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    cout << maxCliques(0, 1) << endl;
    cout << cont << endl;
    for (auto it : cliques)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}