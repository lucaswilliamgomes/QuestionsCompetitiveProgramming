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
        int size, ans = -1;
        cin >> size;
        vector<int> maxIndex(1005, -1);

        for (int i = 0; i < size; i++) {
            int aux;
            cin >> aux;
            maxIndex[aux] = max(maxIndex[aux], i);
        }
        
        for (int i = 1; i < 1005; i++) {
            if (maxIndex[i] == -1) continue;
            for (int j = 1; j < 1005; j++) {
                if (maxIndex[j] == -1) continue;
                if (maxIndex[i] + maxIndex[j] + 2 < ans) continue;

                if (mdc(i, j) == 1) {
                    ans = maxIndex[i] + maxIndex[j] + 2;
                } 
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}