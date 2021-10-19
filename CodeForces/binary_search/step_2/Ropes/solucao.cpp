#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> arr;

bool good(double value) {
    double s = 0;

    for (int i = 0; i < n; i++) {
        s += floor(arr[i] / value);
    }

    return s >= k;
}

int main () {

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0;i < n; i++) {
        cin >> arr[i];
    }

    double l = 0;
    double r = 10e7;
    for(int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (good(m)) {
            l = m; 
        } else {
            r = m;
        }
    }

    cout << setprecision(20) << l << endl;

    return 0;
}