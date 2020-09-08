#include <bits/stdc++.h>

using namespace std;

int main () {
    int total, quant, value;
    set<int> figs;

    cin >> total;
    cin >> quant;

    for (int i = 0; i < quant; i++) {
        cin >> value;
        figs.insert(value);
    }

    cout << (total - figs.size());
    return 0;
}