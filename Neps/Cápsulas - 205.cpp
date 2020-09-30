#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

// MUITO LENTO 
/*
int main(int argc, char const *argv[]){
    ll n, total, cont = 0;
    cin >> n >> total;

    vector <ll> ciclos(n);

    for (ll i = 0; i < n; i++){
        cin >> ciclos[i];
    }

    for (ll i = 1; ; i++){
        for (ll j = 0; j < n; j++){
            if (multiplo(ciclos[j], i)) cont++;

            if (cont == total) {
                cout << i << endl;
                return 0;
            }
        }
    }
}*/


// Utilizando busca binaria 


ll N, F;
ll ciclos [100005];

ll dinheiro (ll days) {
    ll total = 0;

    for (ll i = 0; i < N; i++){
        total += (days / ciclos[i]);
    }

    return total;

}

int main(int argc, char const *argv[]){
   
    cin >> N >> F;

    for (ll i = 0; i < N; i++){
        cin >> ciclos[i];
    }

    // Definindo intervalo da resposta
    ll l = 1, r = 100000000, m;

    while (l < r){
        m = ceil((r+l)/2);
        if (dinheiro (m) >= F) {
            r = m;
        } else if (dinheiro(m) < F) {
            l = m+1;
        }
    }

    cout << l << endl;

    return 0;
    
}