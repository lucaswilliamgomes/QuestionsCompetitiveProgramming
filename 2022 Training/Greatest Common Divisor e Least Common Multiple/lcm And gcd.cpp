#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

vector<long long> lcmAndGcd(long long A, long long B)
{
    vector<long long> ans;
    ans.push_back(lcm(A, B));
    ans.push_back(gcd(A, B));
    return ans;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    vector<long long> ans = lcmAndGcd(a, b);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}