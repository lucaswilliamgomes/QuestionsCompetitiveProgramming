#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int N, casas[MAXN], soma;

int buscaBinaria(int i, int soma, int l, int r) {
    int meio = (l + r) / 2;

    if (casas[i] + casas[meio] == soma) return meio;
    if (l >= r) return -1;
    else {
        if (casas[i] + casas[meio] > soma) return buscaBinaria(i, soma, l, meio-1);
        else if (casas[i] + casas[meio] < soma) return buscaBinaria(i, soma, meio+1, r);
    }
}

int main () {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> casas[i];
    }

    cin >> soma;

    //cout << buscaBinaria(soma, 0, N-1) << endl;

    for(int i = 0; i < N; i++) {
        int casa = buscaBinaria(i, soma, 0, N-1);
        if (casa != -1) {
            cout << casas[i] << " " << casas[casa] << endl; 
            return 0;
        }
    }

    return 0;
}