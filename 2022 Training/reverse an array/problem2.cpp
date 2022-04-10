#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int t, n;
int ar[MAXN];

int solve() {
    int ans = ar[n-1] * ar[n-1];
    bool flag = false;
    for (int i = n-2; i >= 0; i--) {
        if (flag) ans += (ar[i] * ar[i]);
        else ans -= (ar[i] * ar[i]);
        flag = !flag;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        int ans = solve();

        cout << ans << endl;
    }
    return 0;
}
