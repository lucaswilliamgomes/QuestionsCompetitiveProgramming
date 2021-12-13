// TLE
#include <bits/stdc++.h>

using namespace std;

bool ans = false;
vector<int> coins;
int dp[1010][2];
int v, m;

void troco(int i, int falta)
{
    //cout << coins[i] << " " << falta << endl;

    if (i == m || falta < 0) return;
    
    // uso esta moeda
    dp[i][0] = falta - coins[i];
    if (dp[i][0] == 0) {
        ans = true;
        return;
    }
    troco(i+1, dp[i][0]);

    // não uso 
    dp[i][1] = falta;
    if (dp[i][1] == 0) {
        ans = true;
        return;
    }
    troco(i+1, dp[i][1]);
}

int main()
{
    cin >> v >> m;
    coins.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> coins[i];
    }

    troco(0, v);

    if (ans)
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
}