#include <bits/stdc++.h>
#define MAXM 50005
#define MAXN 105

using namespace std;

int m, n, dp[MAXN][MAXM];
vector<int> moedas;

int troco(int idx, int falta) {
    //cout << idx << " " << falta << endl;
    if (falta == 0) return 0;
    if ((falta > 0 && idx == n) || falta < 0 || idx > n) return INT32_MAX - 1;
    if (dp[idx][falta] == -1) {
        dp[idx][falta] = min(troco(idx + 1, falta), 1 + troco(idx, falta - moedas[idx]));
    }
    return dp[idx][falta];
}

int main () {
    while (cin >> m && m) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        moedas.clear();
        moedas.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> moedas[i];
        }
        int ans = troco(0, m);
        if (ans == INT32_MAX - 1) {
            cout << "Impossivel" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}