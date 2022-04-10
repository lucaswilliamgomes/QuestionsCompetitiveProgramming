#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        int aux;
        map<int, int> counter;
        set<int> ans;
        cin >> n >> k;
        //counter.resize(1000000010);
        for (int i = 0; i < n; i++) {
            cin >> aux;

            counter[aux]++;
            if (counter[aux] > k) {
                ans.insert(aux);
            }
        }

        if (ans.size()) {
            for (auto number: ans) {
                cout << number << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }

    }
    return 0;
}
