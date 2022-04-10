// tle
#include <bits/stdc++.h>

using namespace std;

bool verifyPairPalindrome (string a, string b) {
    string ans = a + b;
    map<char, int> counter;
    int countPares = 0;
    int countImpar = 0;

    for (int i = 0; i < ans.size(); i++) {
        counter[ans[i]] += 1;
    }

    for (auto a: counter) {
        if (a.second % 2 == 0) countPares++;
        else countImpar++;
    }
    if (ans.size() % 2 == 0) {
        if (countImpar == 0) return true;
        else return false;
    } else {
        if (countImpar == 1) return true;
        else return false;
    } 
}

int main () {
    int ans = 0, n;
    cin >> n;
    vector<string> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (verifyPairPalindrome(ar[i], ar[j])) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}