#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    if (n == 0) return 0;
    vector<int> left(n), right(n);
    int min_ = prices[0];
    // left[0] = 0;
    for (int i = 1; i < n; i++) {
        min_ = min(prices[i], min_);
        int profit = prices[i] - min_;
        left[i] = max(left[i-1], profit);
    }

    int max_ = prices[n-1];
    //right[n-1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        max_ = max(max_, prices[i]);
        int profit = max_ - prices[i];
        right[i] = max(right[i+1], profit);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, (left[i] + right[i]));
    }

    return ans;
}

int main(int argc, char **argv)
{
    optimize;
    int n;
    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxProfit(nums) << endl;

    return 0;
}