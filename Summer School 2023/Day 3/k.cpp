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

int n, time_s, visit[MAX];
vector<int> ADJ[MAX];

int dfs(int u, int pai, vector<pair<int,int> >& ans){  
    int menor = visit[u] = time_s++;
    int filhos = 0;
    for(int i = 0; i<ADJ[u].size(); i++){
       if(visit[ADJ[u][i]]==0){
          filhos++;
          int m = dfs(ADJ[u][i], u, ans);c
          menor = min(menor,m);
          if(visit[u]<m){
              ans.push_back(make_pair(u, ADJ[u][i]));
          }
       }else if(ADJ[u][i]!=pai){
          menor = min(menor, visit[ADJ[u][i]]);
       }
    } 
    return menor;      
}

vector<pair<int,int> > get_articulacoes(){
    vector<pair<int,int> > ans;
    time_s = 1;
    memset(visit, 0, n*sizeof(int));
    dfs(0,-1,ans);
    return ans;
}


int n, m;
vector<vector<pair<int,int>>> graph(MAXN);

int main(int argc, char **argv)
{
    optimize;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].emplace_back({v, t});
        graph[v].emplace_back({u, t});
    }
    
    

    return 0;
}
