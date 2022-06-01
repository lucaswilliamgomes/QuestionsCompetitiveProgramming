#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;
    while (t--) {
        string ticket;
        cin >> ticket;
        int sum1, sum2;

        sum1 = (int)ticket[0] + (int)ticket[1] + (int)ticket[2];
        sum2 = (int)ticket[3] + (int)ticket[4] + (int)ticket[5];

        if (sum1 == sum2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}