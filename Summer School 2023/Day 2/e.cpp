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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vi ar(a), ag(b), ac(c);

    for (int i = 0; i < a; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < b; i++) {
        cin >> ag[i];
    }

    for (int i = 0; i < c; i++) {
        cin >> ac[i];
    }

    sort(ALL(ag), greater<int>());
    sort(ALL(ar), greater<int>());
    sort(ALL(ac), greater<int>());

    priority_queue<int, vi, greater<int>> pq;

    for (int i = 0; i < x; i++) {
        pq.push(ar[i]);
    }

    for (int i = 0; i < y; i++) {
        pq.push(ag[i]);
    }

    int i = 0;

    while (i < c && pq.top() < ac[i]) {
        pq.pop();
        pq.push(ac[i]);
        i++;
    }

    ll ans = 0;

    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}