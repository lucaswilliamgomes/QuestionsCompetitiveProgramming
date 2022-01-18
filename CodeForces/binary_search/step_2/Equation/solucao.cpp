#include <bits/stdc++.h>
#define lld long double
using namespace std;

lld c;

int good(lld value)
{
    lld k = value * value + sqrt(value);
    if (c == k)
        return 0;
    else if (k > c)
        return 1;
    else if (k < c)
        return -1;
}

int main(int argc, char const *argv[])
{
    cin >> c;

    lld l = 0, r = 10000000, m;

    while (r - l > 1e-7)
    {
        m = (l + r) / 2;
        //cout << m << endl;

        if (good(m) == 1)
        {
            r = m;
        }
        else if (good(m) == -1)
        {
            l = m;
        }
    }

    cout << fixed << setprecision(9) << m << endl;
    return 0;
}
