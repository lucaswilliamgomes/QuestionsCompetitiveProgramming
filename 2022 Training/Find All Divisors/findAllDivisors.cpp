#include <bits/stdc++.h>

using namespace std;

int kThSmallestFactor(int N, int K)
{
    vector<int> ans;

    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            ans.push_back(i);
            if (N % (N / i) == 0 && (N / i) != i)
            {
                ans.push_back((N / i));
            }
        }
    }

    ans.resize(ans.size());
    sort(ans.begin(), ans.end());
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    if (K > ans.size())
        return -1;
    return ans[K - 1];
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << kThSmallestFactor(N, K) << endl;

    return 0;
}