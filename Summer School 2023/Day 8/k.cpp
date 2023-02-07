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

vector<int> graph[MAXN];
vector<char> rank_(MAXN, '-');
bool flag = true;

void dfs(int u, char r) {
    if (rank_[u] != '-') return;

    if (r > 90) flag = false;

    rank_[u] = r;

    for (auto v: graph[u]) {
        dfs(v, char(r + 1));
    }
}

int32_t main(int argc, char **argv)
{
    optimize;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 'A');

    if (!flag) {
        cout << "Impossible!" << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        cout << rank_[i] << " ";
    }

    cout << endl;

    

    return 0;
}