#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Jogador
{
    ll nota;
    string name;

    Jogador(ll nota, string name = "") : nota(nota), name(name) {}

    bool operator<(const Jogador &a)
    {
        return nota < a.nota;
    }

    bool operator>(const Jogador &a)
    {
        return nota > a.nota;
    }
};

vector<Jogador> lista;

int main()
{
    int N, Q, query;
    ll nota;
    string nome;

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> nota >> nome;
        lista.emplace_back(nota, nome);
    }

    sort(lista.begin(), lista.end());

    while (Q--) {
        cin >> query;
        cout << lista[N - query].name << endl;
    }

    return 0;
}