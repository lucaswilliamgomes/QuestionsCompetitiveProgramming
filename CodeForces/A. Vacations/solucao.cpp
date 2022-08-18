#include <bits/stdc++.h>

using namespace std;

int a[110], dp[110][3];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 110; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = INT32_MAX;
        }
    }

    dp[0][0] = 1;

    if (a[0] == 1 || a[0] == 3)
    {
        dp[0][1] = 0;
    }

    if (a[0] == 2 || a[0] == 3)
    {
        dp[0][2] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        // we can always rest
        dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));

        // See if we can do a contestc
        if (a[i] == 1 || a[i] == 3)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }

        // See if we can do a gym
        if (a[i] == 2 || a[i] == 3)
        {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;

    return 0;
}
