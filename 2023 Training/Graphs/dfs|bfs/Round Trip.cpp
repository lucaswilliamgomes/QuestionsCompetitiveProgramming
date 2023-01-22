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
#define MAXN 100100
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;

vector<vector<int>> graph(MAXN);
vector<bool> visiteds(MAXN);
bool find_ans = false;


void print_ans(vector<int> &path) {
    vector<int> ans;

    int start = path[path.size() - 1];
    ans.push_back(start);
    path.pop_back();

    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        ans.push_back(path[i]);
        if (path[i] == start) break; 
    }

    cout <<  ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}


void dfs(int u, int parent, vector<int> &path) {
   if (find_ans) return;

    if (visiteds[u]) {
        if (path.size() > 2) {
            path.push_back(u);
            find_ans = true;
            print_ans(path);
        }
        return;
    }

    visiteds[u] = true;
    path.push_back(u);

    for (auto v: graph[u]) {
        if (v == parent) continue;
        dfs(v, u, path);
    }
    
    path.pop_back();
}



int main(int argc, char **argv)
{
    optimize;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visiteds[i]) continue;
        vector<int> path;
        dfs(i, -1, path);
    }

    if (!find_ans) {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}