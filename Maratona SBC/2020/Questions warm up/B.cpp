#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int N, fib[MAXN];

ll fatorial (int n){
    if(fib[n] != 0) return fib[n];
    else return fib[n] = (n * fatorial(n-1));
}

int main(int argc, char const * argv[]){
    optimize;

    cin>>N;

    for (int i = 0; i < N; i++){
        fib[i] = 0;
    }

    int soma = 0, cont = 0, fat = 0;

    fib[0] = fib[1] = 1;

    for (int i = 0; i < N; i++){
        if (fatorial(i) > N){               
            fat = i-1;
            break;
        }
    }

    while(soma != N)
    {
        if(soma + fatorial(fat) <= N)
        {
            soma += fatorial(fat);
            cont++;
        }
        else{

            fat = fat - 1;
        }

        if(soma == N) break;
    }
    
    cout<< cont <<endl;

    return 0;
}

