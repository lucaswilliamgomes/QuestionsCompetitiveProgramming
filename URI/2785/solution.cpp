#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int matriz[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;

int solve(int pos, int k) {
    if (dp[pos][k]) return dp[pos][k];

    int sum_ = 0;

    for (int i = k; i < k + pos; i++) {
        sum_ += matriz[pos-1][i];
    }
    
    if (pos == 1) {
        return sum_;
    }

    dp[pos-1][k] = solve(pos - 1, k); 
    dp[pos-1][k + 1] = solve(pos - 1, k + 1); 

    return dp[pos][k] = (sum_ + min(dp[pos-1][k], dp[pos-1][k + 1]));
}

int main(int argc, char const *argv[])
{
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << solve(n, 0) << endl;

    return 0;
}
