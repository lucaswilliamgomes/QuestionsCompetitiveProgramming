#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        int turn = 0;

        while(turn < min(n, m) / 2) {
            for (int i = turn; i < m - turn; i++) {
                ans.push_back(matrix[turn][i]);
            }
        
            for (int i = turn + 1; i < n - turn; i++) {    
                ans.push_back(matrix[i][m - turn - 1]);
            }

            for (int i = m - turn - 2; i >= 0 + turn; i--) {    
                ans.push_back(matrix[n - turn - 1][i]);
            }
            
            for (int i = n - turn - 2; i >= 1 + turn; i--) {
                ans.push_back(matrix[i][turn]);
            }

            turn++;
        }

        // if (min(n, m) % 2 != 0) ans.push_back()

        return ans;
    }
};

int main () {
    
    int n, m;
    vector<vector<int>> matrix;

    cin >> n >> m;

    matrix.resize(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution solution;

    vector<int> ans = solution.spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}