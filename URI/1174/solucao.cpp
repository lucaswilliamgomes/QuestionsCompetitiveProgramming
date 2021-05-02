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
    double vet[100];
    for (int i = 0; i < 100; i++){
        cin >> vet[i];
    }
    for (int i = 0; i < 100; i++){
        if (vet[i] <= 10) printf("A[%d] = %.1lf\n", i, vet[i]);
    }
    return 0;
}
