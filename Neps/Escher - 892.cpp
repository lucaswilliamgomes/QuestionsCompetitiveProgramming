#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, aux;
    vector <int> valores;
    vector <int> sum;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> aux;
        valores.push_back(aux);
    }

    if (N % 2 != 0) {
        cout << 'N';
        return 0;
    }

    aux = (N - 1);
    for (int i = 0; i < floor(N/2); i++) {
        sum.push_back(valores[i] + valores[aux-i]);
    }
    aux = sum[0];
    for (int i = 1; i < sum.size(); i++) {
        if (aux != sum[i]){
            aux = -1;
            break;
        }
    }
    
    if (aux == -1) cout << 'N';
    else cout << 'S';
    return 0;
}