// TLE
#include <bits/stdc++.h>
#define MAXN 1010
#define MAXV 100010
using namespace std;

bool ans = false;
vector<int> coins;
int dp[MAXN][MAXV];
int v, m;

int troco(int i, int falta)
{
    if (falta == 0) return 0;
    if ((falta > 0 && i == m) || falta < 0 || i == m) return INT32_MAX - 1;
    if (dp[i][falta] == -1) {
        dp[i][falta] = min(1 + troco(i+1, falta - coins[i]), troco(i+1, falta));
    } 
    return dp[i][falta];
}

int main()
{
    cin >> v >> m;
    coins.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= v; j++) {
            dp[i][j] = -1;
        }
    }

    //cout << troco(0, v) << endl;

    if (troco(0, v) <= coins.size())
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
}