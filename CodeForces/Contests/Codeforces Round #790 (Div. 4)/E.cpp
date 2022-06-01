#include <bits/stdc++.h>

using namespace std;

vector<int> sums;

int binary_search(int value, int l, int r)
{
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (sums[m] < value)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return r;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        sums.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end(), greater<int>());

        sums[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sums[i] = sums[i - 1] + nums[i];
        }

        for (int i = 0; i < k; i++)
        {
            int suggar;
            cin >> suggar;

            int ans = binary_search(suggar, -1, n) + 1;

            if (ans <= n)
            {
                cout << ans << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}