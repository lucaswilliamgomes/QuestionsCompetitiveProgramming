#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        string number;
        cin >> number;
        vector<string> ans;
        for (int i = number.size() - 1; i >= 0; i--) {
            if (number[i] != '0') {
                string round;
                round.push_back(number[i]);
                for (int j = 0; j < number.size() - i - 1; j++) {
                    round.push_back('0');
                }
                ans.push_back(round);
            }
        }

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }



    return 0;
}