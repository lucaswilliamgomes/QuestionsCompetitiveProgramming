#include <bits/stdc++.h>

using namespace std;

int check(string &s, int l, int r) {
    while(true) {
        if (l < 0 || r > s.size() - 1 || s[l] != s[r]) break;
        l--;
        r++;
    }
    l++;
    r--;

    // formar a substring 
    string subs = "";
    for (int i = l; i <= r; i++) {
        subs+=s[i];
    }

    return subs;
}

string longestPalindrome(string s) {

    if (s.size() == 1) {
        return s;
    }

    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        // verificar o maior palindromo de tamanho impar
        // que tem s[i] como centro dela
        string odd = check(s, i, i);
        if (ans.size() < odd.size()) ans = odd;

        // verificar o maior palindromo de tamanho par
        // que tem s[i] como centro dela
        string even = check(s, i, i+1);
        if (ans.size() < even.size()) ans = even;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
