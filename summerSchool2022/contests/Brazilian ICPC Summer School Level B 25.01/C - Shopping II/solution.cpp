#include <bits/stdc++.h>

using namespace std;

vector<int> items, v;
vector<vector<int>> vouchers;

int somaValores()
{
    int soma = 0;
    for (auto it : items)
    {
        soma += it;
    }
    return soma;
}

bool findE(int e, vector<int> ar)
{
    for (auto it : ar)
    {
        if (it == e)
            return true;
    }
    return false;
}

int main()
{
    int testes;
    cin >> testes;

    while (testes--)
    {
        int n, m;
        cin >> n >> m;
        items.clear();
        items.resize(n);
        v.clear();
        v.resize(m);
        vouchers.clear();
        vouchers.resize(m);
        for (int i = 0; i < n; i++)
        {
            cin >> items[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < m; i++)
        {
            int k, aux;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> aux;
                vouchers[i].push_back(aux);
            }
        }
        //cout << findE(1, vouchers[1]) << endl;
        int restante = somaValores();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (restante < 0) {
                    cout << 0 << endl;
                    return 0;
                }
                if (items[i] == 0)
                    break;
                if (findE(i + 1, vouchers[j]))
                {
                    if (items[i] <= v[j])
                    {
                        restante -= items[i];
                        v[j] -= items[i];
                        items[i] = 0;
                    }
                    else
                    {
                        restante -= v[j];
                        items[i] -= v[j];
                        v[j] = 0;
                    }
                }
            }
        }

        cout << restante << endl;
    }

    return 0;
}