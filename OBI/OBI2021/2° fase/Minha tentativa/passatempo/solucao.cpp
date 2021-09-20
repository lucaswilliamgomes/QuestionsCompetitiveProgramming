#include <bits/stdc++.h>
#define INF 2000000020LL
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

string matriz[110][110];
int N, M;
vector<int> colunas, linhas;
map<string, int> ans;
map<string, int>::iterator itr;

bool verifica()
{
    for (itr = ans.begin(); itr != ans.end(); ++itr)
    {
        //cout << itr->first << '\t' << itr->second << '\n';
        if (itr->second == INT_MAX)
        {
            return false;
        }
    }
    return true;
}

void tryResolveLine(int line)
{
    set<string> nEncontrados;
    int soma = linhas[line - 1], cont = 0;
    //cout << "soma " << soma << endl;
    for (int i = 1; i <= M; i++)
    {
        if (ans.at(matriz[line][i]) == INT_MAX)
        {
            nEncontrados.insert(matriz[line][i]);
            cont+=1;
        }
        else
        {
            soma -= ans.at(matriz[line][i]);
        }
    }
    if (nEncontrados.size() == 1)
    {
        string aux;
        for (string it : nEncontrados)
        {
            //cout << "SET " << it << " " << cont << endl;
            aux = it;
        }
        int value = soma / cont;
        map<string, int>::iterator it = ans.find(aux);
        if (it != ans.end())
            it->second = value;

        // cout << "Encontramos o " << aux << " somaInicial " << linhas[line - 1] << " soma "
        //      << soma << " cont " << cont << endl;
    }
}

void tryResolveColumn(int column)
{
    set<string> nEncontrados;
    int soma = colunas[column - 1], cont = 0;
    //cout << "soma " << soma << endl;
    for (int i = 1; i <= N; i++)
    {
        if (ans.at(matriz[i][column]) == INT_MAX)
        {
            nEncontrados.insert(matriz[i][column]);
            cont++;
        }
        else
        {
            soma -= ans.at(matriz[i][column]);
        }
    }

    if (nEncontrados.size() == 1)
    {
        string aux;
        for (string it : nEncontrados)
        {
            //cout << "SET " << it << " " << cont << endl;
            aux = it;
        }
        int value = soma / cont;
        map<string, int>::iterator it = ans.find(aux);
        if (it != ans.end())
            it->second = value;

        // cout << "Encontramos o " << aux << " somaInicial " << colunas[column - 1] << " soma "
        //      << soma << " cont " << cont << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> matriz[i][j];
            ans.insert(pair<string, int>(matriz[i][j], INT_MAX));
        }
        int aux;
        cin >> aux;
        linhas.push_back(aux);
    }

    for (int i = 0; i < M; i++)
    {
        int aux;
        cin >> aux;
        colunas.push_back(aux);
    }

    // procurando as respostas
    while (!verifica())
    {
        //procurando nas linhas
        for (int i = 1; i <= N; i++)
        {
            //cout << "line " << i << endl;
            tryResolveLine(i);
        }
        //procurando nas colunos
        for (int i = 1; i <= M; i++)
        {
            //cout << "column " << i << endl;
            tryResolveColumn(i);
        }
    }

    for (itr = ans.begin(); itr != ans.end(); ++itr)
    {
        cout << itr->first << ' ' << itr->second << '\n';
    }

    return 0;
}
