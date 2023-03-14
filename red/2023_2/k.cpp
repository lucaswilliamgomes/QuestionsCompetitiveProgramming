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


using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

map<pair<string, string>, int> groups;
set<string> types;

int solve(string type) {
    int right = 0, left = 0;
    pair<string, string> aux = {type, "right"};
    right = groups[aux];
    aux = {type, "left"};
    left = groups[aux];
    return max(1, max(left, right));
}

int possible(string type) {
    int right = 0, left = 0, any = 0;
    pair<string, string> aux = {type, "right"};
    right = groups[aux];
    aux = {type, "left"};
    left = groups[aux];
    aux = {type, "any"};
    any = groups[aux];

    return min(left, 1) + min(right, 1) + any;
}

int32_t main(int argc, char **argv)
{   
    int n;
    cin >> n;
    int ans = 0;
    bool isPossible = false;

    for (int i = 0; i < n; i++) {
        string type, side;
        int quant;
        cin >> type >> side >> quant;
        types.insert(type);
        pair<string, string> a = {type, side};
        groups[a] = quant;
    }

    for (auto it: types) {
        ans += solve(it);
    }

    for (auto it: types) {
        // cout << possible(it) << endl;
        if (possible(it) >= 2) {
            isPossible = true;
            break;
        }
    }    

    if (isPossible) cout << ans + 1 << endl;
    else cout << "impossible" << endl;
    return 0;
}