#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll maximumSum(vector<int> ar)
{
    int size = ar.size();

    ll max_so_far = INT_MIN, max_ending = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending += ar[i];
        if (max_ending > max_so_far)
            max_so_far = max_ending;
        if (max_ending < 0)
            max_ending = 0;
    }
    return max_so_far;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cout << maximumSum(ar) << endl;
    return 0;
}
