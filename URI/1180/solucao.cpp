#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int main(int argc, char const *argv[]){
    int n, pos, men;
    cin >> n;
    int vet[n]; 

    for (int i = 0; i < n; i++){
        cin >> vet[i];
    }
    men = vet[0];
    pos = 0;
    for (int i = 0; i < n; i++){
        if (vet[i] < men) {
            men = vet[i];
            pos = i;
        }
    }
    cout << "Menor valor: " << men << endl;
    cout << "Posicao: " << pos << endl;
    return 0;
}
