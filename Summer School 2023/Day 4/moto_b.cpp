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



int main(int argc, char **argv)
{
    optimize;
    int n, m;

    cin >> n >> m;

    int m[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (m[i][j] == 0) m[i][j] = m[i][j+1] - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (m[j][i] == 0) m[j][i] = m[j][i+1] - 1;
        }
    }

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << m[i][j] << " ";
            sum+=m[i][j];
        }
        cout << endl;
    }

    cout << sum << endl;

    return 0;
}