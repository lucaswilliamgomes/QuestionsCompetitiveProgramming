#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, n, ans = 0, current = 0;
    vector<int> vp;
    vp.resize(10000);
    cin >> a >> n;

    for (int i = 0; i < a; i++)
    {
        cin >> vp[i];
    }

    for (int i = 1; i < a; i++)
    {
        if (vp[i] - vp[i - 1] <= n)
        {
            current++;
            ans = max(current, ans);
        }
        else
        {
            current = 0;
        }
    }

    cout << ans + 1 << endl;
}