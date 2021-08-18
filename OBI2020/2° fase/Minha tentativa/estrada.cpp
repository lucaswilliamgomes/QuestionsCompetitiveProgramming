#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int estrada, n;
    vector<float> cidades;
    float cidadesSorted[100000];
    float ans = 10000000;

    cin >> estrada >> n;

    for (int i = 0; i < n; i++)
    {
        float aux;
        cin >> aux;
        cidades.push_back(aux);
    }

    sort(cidades.begin(), cidades.end());

    int cont = 0;
    for (float it : cidades) {
        cidadesSorted[cont] = it;
        cont++;
    }

    for (int i = 0; i < n; i++) {
        float vizinhanca = 0;

        if (i == 0) {
            vizinhanca += (cidades[i] + ((cidades[i + 1] - cidades[i]) / 2));
        } else if (i == n - 1) {
            vizinhanca += (((cidades[i] - cidades[i-1]) / 2) + (estrada - cidades[i]));
        } else {
            vizinhanca += (((cidades[i] - cidades[i - 1]) / 2) + ((cidades[i + 1] - cidades[i]) / 2));
        }

        if (vizinhanca < ans) {
            ans = vizinhanca;
        }
    }

    printf("%.2f\n", ans);
    return 0;
}
