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
    vector<int> amigos;
    for (int i = 0; i < 4; i++)
    {
        int aux;
        cin >> aux;
        amigos.push_back(aux);
    }

    sort(amigos.begin(), amigos.end());

    int time1 = amigos[0] + amigos[3];
    int time2 = amigos[1] + amigos[2];
    int maior = max(time1, time2);
    int menor = min(time1, time2);
    cout << maior - menor << endl;

    return 0;
}
