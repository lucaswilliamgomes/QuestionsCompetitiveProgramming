#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        int ans = 0;
        int wL = ar[0], wR = ar[n-1];
        for (int i = 0, j = n - 1; i < n; ) {
            // cout << wL << " " << wR << endl;
            if (i >= j) break;
            if (wL == wR) ans = i + 1 + (n - j);
            if (wL <= wR) {
                i++;
                wL += ar[i];
                continue;
                
            }

            if (wR <= wL) {
                j--;
                wR += ar[j];
            }
            
            
        }

        cout << ans << endl;
    }



    return 0;
}