#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> numbers;

int main () {
    ll N, K, aux, soma = 0, ans = 0;
    

    cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> aux;
        numbers.push_back(aux);
    }


    for (ll i = 0; i < N; i++) {
        soma += numbers[i];

        if (soma == K) {
            ans++;
        }

        if (soma > K) {
            soma = 0;
            continue;
        }

        
        for (ll j = (i+1); j < N; j++){

            soma += numbers[j];
            //cout << numbers [i] << " " <<  numbers[j] << " " << soma << endl;
            if (soma == K) ans++;

            if (soma > K){
                soma = 0;
                break;
            }
        }  
    }

    cout << ans << endl;
    return 0;
}