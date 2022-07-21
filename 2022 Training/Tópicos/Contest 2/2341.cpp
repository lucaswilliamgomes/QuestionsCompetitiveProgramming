#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k;

    map<int,int> figs;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        figs[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        figs[aux]++;
    }

    bool flag = true;
    int min_ = INT32_MAX;

    for (auto it: figs) {
        if (!it.second) {
            flag = false;
        }
        min_ = min(min_, it.second);
    }

    if (flag) {
        cout << min_ << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}