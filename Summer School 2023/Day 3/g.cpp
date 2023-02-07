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

vector<int> graph[MAXN];
vector<int> degree;
vector<int> ans;
int N, M;

int main(int argc, char **argv)
{
    optimize;
    cin >> N >> M;

    degree.resize(N);
    ans.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    int min_ = INT32_MAX;
    int index_min = -1;

    for (int i = 0; i < N; i++) {
        ans[i] = 1;
        if (degree[i] < min_) {
            min_ = degree[i];
            index_min = i;
        }
    }

    ans[index_min] = 0;
    for (auto v: graph[index_min]) {
        ans[v] = 0;
    }

    for (int i = 0; i < N; i++ ) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}