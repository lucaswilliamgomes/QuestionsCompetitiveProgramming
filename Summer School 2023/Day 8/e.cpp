#include <bits/stdc++.h>

#define ms 201000

using namespace std;

vector<int> g[ms];
int dis[ms][30];
int par[ms], sz[ms], rem[ms], h[ms];
vector<int> ans;


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
  ans.push_back(ctr);
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

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 0; i < n -1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    decompose(1);

    cout << ans[0] << endl;

    return 0;
}
