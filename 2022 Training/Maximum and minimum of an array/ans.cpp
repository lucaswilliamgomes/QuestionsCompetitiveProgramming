#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
    long long min_ = INT32_MAX, max_ = -INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_) {
            min_ = a[i];
        }

        if (a[i] > max_) {
            max_ = a[i];
        }
    }

    pair<long long, long long> ans(min_, max_);
    return ans;
}

int main () {
    long long ar[MAXN];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    pair<long long, long long> ans = getMinMax(ar, n);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}