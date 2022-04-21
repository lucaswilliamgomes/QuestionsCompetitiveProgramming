#include <bits/stdc++.h>

using namespace std;

set<int> ans;
vector<int> quant;

int main () {

    int t, n, aux;
    cin >> t;

    while (t--) {
        ans.clear();
        quant.clear();
        cin >> n;
        quant.resize(n+1);
        for (int i = 0; i < n; i++) {
            cin >> aux;
            quant[aux]++;
        }

        for (int i = 0; i < n+1; i++) {
            
            if (quant[i] >= 3) {
                ans.insert(i);
            }
        }

        if (ans.size() == 0) {
            cout << -1 << endl;
        } else {
            for (auto it : ans) {
                cout << it << endl;
                break;
            }
            // cout << endl;
        }
        
    }

    return 0;
}