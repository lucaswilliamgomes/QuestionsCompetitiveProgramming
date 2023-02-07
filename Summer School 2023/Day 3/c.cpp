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

int n, m, q; // number of nodes
vector<int> adj[MAXN]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
int pai[MAXN];

int find(int u) {
    if (pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void IS_BRIDGE(int u, int v) {
    u = find(u);
    v = find(v);
    pai[u] = v;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    
}

void clear() {
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        adj[i].clear();
    }
}

int main(int argc, char **argv)
{
    optimize;

    while ((cin >> n >> m >> q) && (n || m || q)) {
        clear();
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        find_bridges();

        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;

            if (find(u) == find(v)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }

        }

        cout << "-" << endl;
    } 
   
    

    return 0;
}