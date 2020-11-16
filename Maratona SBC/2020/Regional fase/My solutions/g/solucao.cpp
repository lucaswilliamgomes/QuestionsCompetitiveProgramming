#include <bits/stdc++.h>

using namespace std;

vector <int> caixas;

int teste (int a) {
    int total = 100;
    for (int i = 0; i < a; i++){
        total += caixas[i];
    }
    return total;
}

int main () {
    
    int n, ans = 100;
    cin >> n;
    for (int i = 0, aux; i < n; i++){
        cin >> aux;
        caixas.push_back(aux);
    }

    for (int i = 1, aux; i <= n; i++){
        if (teste(i) > ans) ans = teste(i);
    }

    cout << ans << endl;

    return 0;
}