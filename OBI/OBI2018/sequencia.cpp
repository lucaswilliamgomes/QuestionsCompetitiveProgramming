// errada
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, l, h;
int lista[10000];
int marcados[10000];

ll somaMaximaAtual(int atual)
{
    vector<ll> somas;
    ll somaMaxima = LONG_LONG_MIN, soma = 0;
    int marcas = 0;
    for (int i = atual; i < n; i++)
    {
        if (marcados[i])
        {
            if (marcas == h)
                break;
            marcas++;
        }
        soma += lista[i];
        if (marcas >= l and marcas <= h)
        {
            somas.push_back(soma);
        }
    }
    for (ll it : somas)
    {
        if (it > somaMaxima)
            somaMaxima = it;
    }
    return somaMaxima;
}

int main(int argc, char const *argv[])
{
    ll somaMaxima = LONG_LONG_MIN;
    cin >> n >> l >> h;

    for (int i = 0; i < n; i++)
    {
        cin >> lista[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> marcados[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll somaAtual = somaMaximaAtual(i);
        if (somaAtual > somaMaxima)
            somaMaxima = somaAtual;
    }

    cout << somaMaxima << endl;
    return 0;
}
