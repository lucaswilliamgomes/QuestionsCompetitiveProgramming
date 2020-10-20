#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

set <int> materias;

int main(int argc, char const *argv[]){
    ll n, aux;
    cin >> n;

    for (ll i = 0; i < n; i++){
        cin >> aux;
        materias.insert (aux);
    }

    cout << materias.size() << endl;

    
    return 0;
}