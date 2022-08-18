#include <bits/stdc++.h>

using namespace std;

vector<int> stalls;

bool solve(int c, int m) {
    int k = 1;
    int ultima_vaca = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - ultima_vaca >= m) {
            k++;
            ultima_vaca = stalls[i];
        }
    }

    if (k >= c) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        int n, c;
        cin >> n >> c;

        stalls.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        sort(stalls.begin(), stalls.end());
        
        int ans = 0;
        int l = 0, r = 1000000000;
        int m;

        while (l <= r) {
            m = l + ((r - l) / 2);
            if (solve(c, m)) {
                l = m + 1;
                ans = m;
            } else {
                r = m - 1;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
