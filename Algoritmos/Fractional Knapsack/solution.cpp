#include <bits/stdc++.h>

using namespace std;

struct Objeto
{
    double valor;
    double peso;
    double valorRelativo;

    bool operator<(const Objeto &a)
    {
        return valorRelativo < a.valorRelativo;
    }

    bool operator>(const Objeto &a)
    {
        return valorRelativo > a.valorRelativo;
    }
};

double fractionalSnapsack(vector<Objeto> objetos, int n, double capacidade) {
    vector<double> quantidades(n);

    sort(objetos.begin(), objetos.end());        // O(n logn)

    double resposta = 0;

    for(int i = n - 1; i >= 0; i--) {            // O(n)
        if (objetos[i].peso <= capacidade) {
            quantidades[i] = 1;
            resposta += objetos[i].valor;
            capacidade -= objetos[i].peso;
        } else {
            quantidades[i] = capacidade / objetos[i].peso;
            resposta += quantidades[i] * objetos[i].valor;
            capacidade = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Objeto de valor " << objetos[i].valor << " e peso " << objetos[i].peso;
        cout << " fracao colocada na mochila " << quantidades[i] << endl;
    }

    cout << endl;

    return resposta;
}

int main(int argc, char const *argv[])
{
    vector<Objeto> objetos;
    int n, c;
    cout << "Digite a quantidade de objetos e a capacidade da mochila respectivamento: " << endl;
    cin >> n >> c;
    objetos.resize(n);
    cout << "Digite o valor e o peso de cada produto em cada linha respectivamente: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> objetos[i].valor >> objetos[i].peso;
        objetos[i].valorRelativo = objetos[i].valor/objetos[i].peso;
    }

    double valorTotal = fractionalSnapsack(objetos, n, c);

    cout << endl << "O valor maximo que a mochila pode levar eh: " << valorTotal << endl; 
    
    return 0;
}
