#include <bits/stdc++.h>

using namespace std;

int verifyDiff(string word1, string word2)
{
    int ans = 0;

    for (int i = 0; i < word1.size(); i++)
    {
        if (word1[i] != word2[i]) {
            ans += abs(min((word1[i] - word2[i]), (word2[i] - word1[i])));
        }
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, min_ = INT_MAX;
        cin >> n >> k;
        vector<string> words(n);

        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }

        for (int i = 0; i < (n - 1); i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                min_ = min(min_, verifyDiff(words[i], words[j]));
            }
        }

        cout << min_ << endl;
    }
    return 0;
}