#include <bits/stdc++.h>

using namespace std;

vector<int> minimumSum(vector<int> a)
{

    vector<int> ans;
    int size = a.size();
    for (int j = 0; j < size; j++)
    {
        int minimum_so_far = INT_MAX, minimum_ending_here = 0;
        for (int i = j; i < size; i++)
        {
            minimum_ending_here += a[i];
            if (minimum_ending_here < minimum_so_far)
            {
                minimum_so_far = minimum_ending_here;
            }
            

            if (minimum_ending_here > 0)
            {
                minimum_ending_here = 0;
            }
        }
        ans.push_back(minimum_so_far);
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ans = minimumSum(a);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}