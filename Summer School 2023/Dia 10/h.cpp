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
#define int long long

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

unsigned int countBits(unsigned int v) {
    unsigned int c; // store the total here

    v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
    c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count

    return c;
}


int32_t main(int argc, char **argv)
{
    optimize;

    int n, b;
    cin >> n >> b;
    unsigned int ans = 0;
    cout << pow(2, 120) << endl;
    // for (int i = n; i <= pow(2, b) - 1; i+=n) {
    //     ans += countBits(i);
    //     cout << i << " " << ans << endl;
    // }

    // cout << ans << endl;

    

    

    return 0;
}