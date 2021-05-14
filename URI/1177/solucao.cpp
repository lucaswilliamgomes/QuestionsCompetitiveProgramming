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
    int n, vet[1000], aux = 0;
    cin >> n;
    for (int i = 0; i < 1000; i++){
        if (aux == n) aux = 0;
        vet[i] = aux;
        aux++;
    }
    for (int i = 0; i < 1000; i++){
        printf ("N[%d] = %d\n", i, vet[i]);
    }
    return 0;
}
