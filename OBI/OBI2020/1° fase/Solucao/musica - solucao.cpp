#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020


using namespace std;

int O[MAXN], A[MAXN], D[MAXN];
bool vis[MAXN];

int main(int argc, char const *argv[]){
    int n, m ,c;

    for (int i = 0; i < MAXN; i++){
        O[i] = -1;
    }

    cin >> n >> m >> c;

    for (int i = 0; i < n; i++){
        cin >> A[i] >> D[i];

        if (O[D[i]] == -1) {
            O[D[i]] = i;
        }
    }

    int ans = 0;

    while (!vis[c] && O[c] != -1){
        vis[c] = true;
        c = A[O[c]];
        ans++;
    }

    cout << (vis[c] ? -1 : ans) << endl;

}