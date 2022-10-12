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

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (int i = 0; i < (int)nums1.size(); i++) {
        if (!nums2.size()) return ans;

        int k = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
        if( k >= 0 && k < nums2.size() &&  nums2[k] == nums1[i]) {
            nums2.erase(nums2.begin() + k);
            ans.push_back(nums1[i]);
        }
    }

    return ans;
}

int main(int argc, char **argv)
{
    optimize;
    int n;
    cin >> n;
    vi nums1(n);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cin >> n;
    vi nums2(n);

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    vi ans = intersect(nums1, nums2);

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}