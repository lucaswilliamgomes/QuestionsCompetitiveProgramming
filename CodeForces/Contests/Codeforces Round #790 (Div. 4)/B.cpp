#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;
    while (t--) {
        int n, min_ = INT_MAX;
        cin >> n;
        vector<int> boxes(n);

        for (int i = 0; i < n; i++) {
            cin >> boxes[i];
            if (boxes[i] < min_) {
                min_ = boxes[i];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (boxes[i] > min_) {
                ans += (boxes[i] - min_);
            }
        }

        cout << ans << endl;
    }
    return 0;
}