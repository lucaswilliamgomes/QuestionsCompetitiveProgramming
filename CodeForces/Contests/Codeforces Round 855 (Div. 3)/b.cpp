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

int32_t main(int argc, char **argv)
{
    optimize;
    int t;
    cin >> t;
    while (t--) {
        int size, k;
        string s;
        cin >> size >> k >> s;
        int ans = 0;

        map<char, int> mp;

        for (auto c: s) {
            mp[c]++;
        }

        for (auto m: mp) {
            if (isupper(m.first)) {
                int aux = min(mp[m.first], mp[tolower(m.first)]);
                mp[m.first]-=aux; mp[tolower(m.first)]-=aux;
                ans += aux;
            }
        }

        for (auto m: mp) {
            while (m.second >= 2 && k > 0) {
                m.second -= 2;
                k -= 1;
                ans++;
            }
        }

        cout << ans << endl;
        
    }
    
    return 0;
}