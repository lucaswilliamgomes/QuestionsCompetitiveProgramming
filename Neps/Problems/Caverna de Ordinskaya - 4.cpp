#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m, aux, atual, anterior = 0;
    long long ans = 0;
    vector <int> fita; 
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> aux;
        fita.push_back(aux);
    }

    for (int i = 0; i < n; i++){
        if (i == 0){
            atual = min (fita[i], m - fita[i]);
            ans += atual;
            anterior = atual;
            continue;
        }
        atual = min (fita[i], m - fita[i]);

        if (atual < anterior){
            atual = max(fita[i], m - fita[i]);
            if (atual < anterior){
                cout << -1 << endl;
                return 0;
            }
        }

        ans += atual;
        anterior = atual;

    }
    cout << ans << endl;

    return 0;
}