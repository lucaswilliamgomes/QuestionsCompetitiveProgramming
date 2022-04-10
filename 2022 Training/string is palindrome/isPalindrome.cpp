#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    for (int l = 0, r = str.size() - 1; l < (str.size() / 2); l++) {
        if (str[l] != str[r]) return false;
        r--;
    }

    return true;
}

int main () {
    string s;
    cin >> s;

    if (isPalindrome(s)) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}



