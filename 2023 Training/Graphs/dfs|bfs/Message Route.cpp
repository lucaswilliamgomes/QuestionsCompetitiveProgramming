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

int n, m;
vector<vector<int>> graph(MAXN);
vector<bool> visiteds(MAXN);
vector<int> prev_(MAXN);

int main(int argc, char **argv)
{
    optimize;
    cin >> n >> m;

    for (int i = 0;i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // bfs
    int start = 1, end = n;
    queue<int> bfs;
    bfs.push(start);

    while(!bfs.empty() ) {
        int u = bfs.front();
        bfs.pop();
        visiteds[u] = true;

        for (auto v : graph[u]) {
            if (!visiteds[v]) {
                visiteds[v] = true;
                prev_[v] = u;
                bfs.push(v);
            }
        }
    }

    if (!visiteds[end]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int dist = 0;
    int curr = end;
    vector<int> ans;

    while (curr != start) {
        ans.push_back(curr);        
        curr = prev_[curr];
        dist += 1;
    }

    ans.push_back(start);
    reverse(ans.begin(), ans.end());
    cout << dist + 1 << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}