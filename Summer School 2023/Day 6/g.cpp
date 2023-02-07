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


int N;
deque<int> a;

int getMin() {
    int r = INT32_MAX;
    for (auto it: a) {
        if (it < r) r = it;
    }
    return r;
}

int32_t main(int argc, char **argv)
{
    optimize;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int aux;
        cin >> aux;
        a.push_back(aux);
    }

    reverse(ALL(a));

    int ans = 0;

    while (!a.empty()) {
        int min_ = getMin();

        if (a.back() == min_) {
            a.pop_back();
        } else {
            a.push_front(a.back());
            a.pop_back();
        }

        ans++;
    }

    cout << ans << endl;


    return 0;
}