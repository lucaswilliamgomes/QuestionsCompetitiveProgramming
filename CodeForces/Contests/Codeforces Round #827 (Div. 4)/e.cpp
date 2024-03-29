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
#define MAXN 201010
#define MAXL 23
#define endl '\n'
#define int ll

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int mdc (int a, int b) {
    if (b == 0) return a;
    else return mdc(b, a % b); 
}


int32_t main(int argc, char **argv)
{
    optimize;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n), diff(n), tam(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (i == 0) {
                diff[i] = nums[i];
                tam[i] = nums[i];
            } else {
                diff[i] = max(diff[i - 1], nums[i]);
                tam[i] = tam[i-1] + nums[i];
            }
        }

        for (int i = 0; i < q; i++) {
            int question;
            cin >> question;

            int index = upper_bound(diff.begin(), diff.end(), question) - diff.begin() - 1;

            if (index == -1) cout << 0 << " ";
            else cout << tam[index] << " ";
        }
        cout << endl;
    }
    
    return 0;
}