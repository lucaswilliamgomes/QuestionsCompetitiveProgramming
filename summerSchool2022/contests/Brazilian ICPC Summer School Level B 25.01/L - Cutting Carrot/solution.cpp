// TLE
#include <bits/stdc++.h>
#define lld double
using namespace std;

lld H, N;

int good(lld height, lld areaAtual)
{
    double baseMenor = height / H;
    double areaMenor = (baseMenor * height) / 2;

    if (areaMenor == areaAtual)
        return 0;
    else if (areaMenor > areaAtual)
        return 1;
    else
        return -1;
}

int main()
{
    cin >> N >> H;
    lld areaBase = (H/2)/N;
    for (int i = 1; i < N; i++)
    {
        lld l = 0, r = H, m, areaAtual = areaBase * i;
        while (r - l > 1e-7)
        {
            m = (l + r) / 2;
            if (good(m, areaAtual) == 1)
            {
                r = m;
            }
            else if (good(m, areaAtual) == -1)
            {
                l = m;
            }
        }
        cout << fixed << setprecision(12) << m << " ";
    }
    cout << endl;

    return 0;
}