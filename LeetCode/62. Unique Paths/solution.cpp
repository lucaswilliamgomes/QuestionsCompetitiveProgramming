#include <bits/stdc++.h>

using namespace std;

int solve(int currentM, int currentN, int total, vector<vector<int>> &dp) {
    if (dp[currentM][currentN] != -1) return dp[currentM][currentN];
    if (dp[currentN][currentM] != -1) return dp[currentN][currentM];
    
    if (currentN == 0 || currentM == 0) return dp[currentM][currentN] = 0;
    if (currentN == 1 && currentM == 1) return dp[currentM][currentN] = 1;
    if ((currentN == 2 && currentM == 1) || (currentN == 1 && currentM == 2))  
        return dp[currentM][currentN] = 1;
    
    total = solve(currentM - 1, currentN, total, dp) + solve(currentM, currentN - 1, total, dp);

    return dp[currentM][currentN] = total;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(105, vector<int>(105, -1));
    return solve(m, n, 0, dp);
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m) << endl;
}

