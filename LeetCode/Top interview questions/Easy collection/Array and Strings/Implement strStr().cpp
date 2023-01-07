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


int strStr(string haystack, string needle) {
    for (int l = 0, r = 0; l + r < haystack.size(); ) {
        if (haystack[l + r] != needle[r]) {
            l++;
            r = 0;
            continue;
        } else {
            if (r == needle.size() - 1) return l;
            else r++;
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    optimize;
    string s, k;
    cin >> s >> k;
    cout << strStr(s, k) << endl;
    return 0;
}