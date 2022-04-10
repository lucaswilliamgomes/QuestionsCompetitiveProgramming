#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Armazena os vértices
int store[MAX], n;

int graph[MAX][MAX];

// Função para verificar se o conjunto dado de
// vertices no array store é um clique ou não
bool is_clique(int b)
{
    // Para todo o conjunto de arestas
    for (int i = 1; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
            // Se alguma aresta estiver faltando ..
            if (graph[store[i]][store[j]] == 0)
                return false;
    }
    return true;
}

// Função para encontrar o tamanho
// do(s) clique(s) máximo(s)
int maxCliques(int i, int l)
{
    // Para guardar o tamanho do maior clique encontrado até agora
    int max_ = 0;

    // Verifica se algum vértice de i+1
    // pode ser inserido
    for (int j = i + 1; j <= n; j++)
    {
        // Add o vertice no store
        store[l] = j;

        // Se o grafo não for um clique de tamanho k então
        // não pode ser um clique adicionando outra aresta
        if (is_clique(l + 1))
        {
            // atualiza max
            max_ = max(max_, l);

            // Verifique se outra aresta pode ser adicionada
            max_ = max(max_, maxCliques(j, l + 1));
        }
    }
    return max_;
}

int main()
{
    int edges[][2] = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4},
        {4, 5},
        {4, 6},
        {5, 6},
    };

    int size = sizeof(edges) / sizeof(edges[0]);
    n = 6;

    for (int i = 0; i < size; i++)
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    cout << maxCliques(0, 1) << endl;

    return 0;
}