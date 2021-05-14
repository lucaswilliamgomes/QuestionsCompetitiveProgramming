#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

ll fibs[100];

ll fib(int k)
{   
    if (fibs[k]) return fibs[k];
    if (k == 0) return fibs[k] = 0;
    if (k == 1) return fibs[k] = 1;
    return fibs[k] = fib(k-1) + fib(k-2);
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;

    while (n--)
    {
        cin >> k;
        printf("Fib(%d) = %lld\n", k, fib(k));
    }

    return 0;
}
