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

#define ms 20010
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int N;
vector<int> centroids;


vector<int> g[ms];
int dis[ms][30];
int par[ms], sz[ms], rem[ms], h[ms];

void dfsSubtree(int u, int p) {
  sz[u] = 1;
  for(auto v : g[u]) {
    if(v != p && !rem[v]) {
      dfsSubtree(v, u);
      sz[u] += sz[v];
    }
  }
}

int getCentroid(int u, int p, int size) {
  for(auto v : g[u]) {
    if(v != p && !rem[v] && sz[v] * 2 >= size) 
      return getCentroid(v, u, size);
  }
  return u;
}

void setDis(int u, int p, int nv){
  for (auto v : g[u]) {
    if (v == p || rem[v]) continue;
    dis[v][nv] = dis[u][nv]+1;
    setDis(v, u, nv);
  }
}

void decompose(int u, int p = -1, int nv = 0) {
  dfsSubtree(u, -1);
  int ctr = getCentroid(u, -1, sz[u]);
  centroids.push_back(ctr);
  par[ctr] = p; 
  h[ctr] = nv; 
  rem[ctr] = 1;
  setDis(ctr, p, nv);
  for(auto v : g[ctr]) {
    if(v != p && !rem[v]) {
      decompose(v, ctr, nv+1);
    }
  }
}


int32_t main(int argc, char **argv)
{
    cin >> N;

    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    decompose(1);

    centroids[0]



    return 0;
}