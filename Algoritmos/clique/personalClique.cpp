#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

vector<int> grafo[MAXN];
map<int, int> degrees;

int tamCliqueMaximo = 0;
vector<int> cliqueMaximo;

void subsetsUtil(vector<int> &A, vector<vector<int>> &res,
                 vector<int> &subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++)
    {
        subset.push_back(A[i]);

        subsetsUtil(A, res, subset, i + 1);

        subset.pop_back();
    }

    return;
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<int> subset;
    vector<vector<int>> res;

    int index = 0;

    subsetsUtil(A, res, subset, index);

    return res;
}

// Verifica se todos os vértices de um subgrafo estão interligados
// onde grafo é uma matriz de adjacência e o subgrafo é uma lista de vértices.
// Explicação: Para cada vértice do subgrafo eu verifico se ele está ligado a todos os outros
// vértices desse subgrafo atravez da minha matriz de adjacência que guarda os nós do grafo.
bool ehUmSubgrafoCompleto(vector<int> subgrafo)
{
    if (subgrafo.size() > 1)
    {
        for (int j = 0; j < subgrafo.size() - 1; j++)
        {
            for (int k = j + 1; k < subgrafo.size(); k++)
            {
                if (find(grafo[subgrafo[j]].begin(), grafo[subgrafo[j]].end(), subgrafo[k]) == grafo[subgrafo[j]].end())
                    return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> findCliqueMaximo(vector<vector<int>> subgraphs)
{
    vector<int> ans;
    for (int i = 0; i < subgraphs.size(); i++)
    {
        if (ehUmSubgrafoCompleto(subgraphs[i]))
        {
            if (subgraphs[i].size() > ans.size())
            {
                ans = subgraphs[i];
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int edges[][2] = {
        {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {3, 6}, {4, 5}, {4, 6}, {5, 6}};
    int n = 6;
    int quantArestas = sizeof(edges) / sizeof(edges[0]);
    vector<int> vertices(n);

    for (int i = 1; i <= n; i++)
    {
        vertices[i - 1] = i;
    }

    for (int i = 0; i < quantArestas; i++)
    {
        int u, v;
        u = edges[i][0];
        v = edges[i][1];
        grafo[u].push_back(v);
        grafo[v].push_back(u);
        degrees[u]++;
        degrees[v]++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << i << " - grau " << degrees[i] << " <- ";
        for (auto it : grafo[i])
        {
            cout << " " << it;
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> subgraphs = subsets(vertices);

    vector<int> ans = findCliqueMaximo(subgraphs);

    cout << "O clique máximo encontrado tem tamanho " << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
