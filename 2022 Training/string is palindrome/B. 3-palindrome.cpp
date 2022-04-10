#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, count1 = 0, count2 = 0;
    cin >> n;
    string ans;
    vector<char> letters = {'a', 'b'};
    for (int i = 0; i < n; i++) {
        if (count2 == 2) {
            count2 = 0;
            count1++;
        }
        count2++;

        if (count1 == 2) count1 = 0;
 
        ans+=letters[count1];
    }

    cout << ans << endl;


    return 0;
}