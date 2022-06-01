#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        int chess[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> chess[i][j];
            }
        }

        int sum_;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum_ = 0;
                sum_ += chess[i][j];

                for (int k = 1; ; k++) {
                    int cont = 0;

                    if (i - k >= 0 && j - k >= 0) {

                        sum_ += chess[i-k][j-k];
                        cont++;
                    }

                    if (i - k >= 0 && j + k < m) {

                        sum_ += chess[i-k][j+k];
                        cont++;
                    }

                    if (i + k < n && j + k < m) {

                        sum_ += chess[i+k][j+k];
                        cont++;
                    }

                    if (i + k < n && j - k >= 0) {
                        
                        sum_ += chess[i+k][j-k];
                        cont++;
                    }

                    if (cont == 0) break;
                }

                ans = max(ans, sum_);
            }
        }

        cout << ans << endl;

    }

    return 0;
}