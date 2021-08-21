#include <bits/stdc++.h>
#define INF 2000000020LL
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int main(int argc, char const *argv[])
{
    int e1, e2, e3, x;
    cin >> e1 >> e2 >> e3 >> x;

    if (modulo(e2 - e1) <= x)
        cout << e2 << endl;
    else
        cout << e3 << endl;

    return 0;
}
