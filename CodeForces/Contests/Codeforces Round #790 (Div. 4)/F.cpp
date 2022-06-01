#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, K;
        cin >> n >> K;

        map<int, int> numsQuant;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            numsQuant[aux]++;
        }

        vector<int> ans;

        for (auto x : numsQuant)
        {
            if (x.second >= K)
            {
                ans.push_back(x.first);
            }
        }

        if (ans.size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int l = ans[0], r = ans[0];
            int currentMax = 0;
            int totalMax = 0;

            for (int i = 1, currentL = 0; i < ans.size();)
            {
                if (ans[i] == ans[i - 1] + 1)
                {
                    currentMax++;
                    if (currentMax > totalMax)
                    {
                        totalMax = currentMax;
                        r = ans[i];
                        l = ans[currentL];
                    }
                    i++;
                }
                else
                {
                    currentMax = 0;
                    currentL += 1;
                    i = currentL + 1;
                }
            }

            cout << l << " " << r << endl;
        }
    }

    return 0;
}