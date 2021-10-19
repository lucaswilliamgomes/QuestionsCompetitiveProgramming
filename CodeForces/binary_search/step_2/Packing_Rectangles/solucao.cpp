#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll w, h, n;

bool good(ll value)
{
    return (value / w) * (value / h) >= n;
}

int main()
{
    cin >> w >> h >> n;

    ll l = 0;
    ll r = 1;

    while (!good(r))
        r *= 2;

    while (r > l + 1)
    {
        ll m = (l + r) / 2;
        if (good(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << r << endl;

    return 0;
}