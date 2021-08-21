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
    pair<int, int> dimensoes;
    float azuis, brancos, ans = 0, h = 1;
    cin >> azuis >> brancos;

    while (h != brancos)
    {
        float leng = brancos / h;
        if (roundf(leng) == leng)
        {
            float tempAzuis = ((h + 2) * 2) + (leng * 2);
            if (tempAzuis == azuis)
            {
                dimensoes.first = (int)(h + 2);
                dimensoes.second = (int)(leng + 2);
                ans = 1;
                break;
            }
        }
        h++;
    }

    if (ans)
    {
        int maior = max(dimensoes.first, dimensoes.second);
        int menor = min(dimensoes.first, dimensoes.second);
        cout << menor << " " << maior << endl;
    }
    else
    {
        cout << -1 << " " << -1 << endl;
    }

    return 0;
}
