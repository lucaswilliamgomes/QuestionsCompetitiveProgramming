// TLE

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ll pos, deslizes;
    int aux, memoria;

    cin >> pos >> deslizes;

    vector <int> ans (10, 0);
    vector <int> barra;

    for (ll i = 0; i < pos; i++) {
        cin >> aux;
        barra.push_back(aux); // pos i = i - 1
    }   

    aux = 0;

    for (ll i = 0; i < deslizes; i++){
        memoria = aux;
        cin >> aux;
        if (i == 0) continue;

        if (memoria < aux) {
            for (int j = memoria-1; j < aux-1; j++){
                ans[barra[j]]++; 
            }
        } else {
            for (int j = memoria-1; j > aux-1; j--){
                ans[barra[j]]++;
            }
        }

        if (i == deslizes - 1) ans[barra[aux-1]]++;
    }

    for (int i = 0; i < 10; i++){
        cout << ans[i] << " ";
    }

    return 0;
}