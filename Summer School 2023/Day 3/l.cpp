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

int N, M;
vector<pair<int,int>> edges;
vector<bool> del_edges;
vector<int> graph[MAXN];
int pai[MAXN];

int find_(int u) {
    if (pai[u] == u) return u;
    else return pai[u] = find_(u);
}

void merge(int a, int b) {
    int u = find_(a);
    int v = find_(b);

    if (u != v) 
        pai[a] = v;
}

int main(int argc, char **argv)
{
    optimize;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        pai[i] = i;
    }

    del_edges.resize(M);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int k;
    cin >> k;

    for (int i = 1, j = 0; i <= k; i++) {
        int aux; cin >> aux;
        del_edges[aux] = true;
    }

    for (int i = 1; i <= M; i++) {
        if (del_edges[i]) continue;

        graph[edges[i - 1].first].push_back(edges[i - 1].second);
        merge(edges[i - 1].first, edges[i - 1].second);
    }

    set<int> p;

    for (int i = 1; i <= N; i++) {
        p.insert(pai[i]);
    }

    for (int i = k-1; i >= 0; i--) {
        cout << p.size() - i << " ";
    }

    cout << endl;

    return 0;
}