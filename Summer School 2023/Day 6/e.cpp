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
#define int long long

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int N;
vector<int> ar;


vector<pair<int, int>> info;

int32_t main(int argc, char **argv)
{
    optimize;
    cin >> N;
    ar.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> ar[i];

        int sq = (int)sqrt(ar[i]);
        if (sq * sq == ar[i]) {
            info.push_back({0, i});
        } else {
            info.push_back({min(abs(ar[i] - (sq * sq)), abs(ar[i] - (sq + 1) * (sq + 1))), i});
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << info[i].first << " " << info[i].second << endl;
    // }

    sort(ALL(info));

    int ans = 0;
    for (int i = 0; i < N/2; i++) {
        ans+=info[i].first;
    }

    for (int i = N/2; i < N; i++) {
        cout << info[i].second << " " << info[i].first << endl;
        if (!info[i].first) {
            // verifico se ar[i] é 0
            if (ar[info[i].second] == 0) ans += 2;
            else ans += 1;
        }
    }




    cout << ans << endl;




    return 0;
}