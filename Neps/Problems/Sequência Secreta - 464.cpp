#include <bits/stdc++.h>

using namespace std;

int main () {
    int tam, num, ans = 0;
    vector <int> sequencia;
    cin >> tam;

    for (int i = 0; i < tam; i++) {
        cin >> num;
        sequencia.push_back(num);
    }

    for (int i = 0; i < (tam-1); i++) {
        if(sequencia[i] != sequencia[i+1]) ans++;
    }

    cout << ans + 1;

    return 0;
}