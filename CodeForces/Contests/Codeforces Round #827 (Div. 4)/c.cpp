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
        char matrix[8][8];
        bool hadCompleteLines = false;
        int countR = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 'R') countR++;
                if (countR == 8) hadCompleteLines = true;
            }
            countR = 0;
        }

        if (hadCompleteLines) cout << "R" << endl;
        else cout << "B" << endl;
    }
    
    return 0;
}