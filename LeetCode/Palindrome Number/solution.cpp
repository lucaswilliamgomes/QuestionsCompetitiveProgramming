#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPalindrome(int x) {
    string word = to_string(x);
    int init = 0, end = word.size() - 1;
    while(init < end) {
        // cout << word[init] << " " << word[end] << endl;
        if (word[init] != word[end]) return false;
        init++;
        end--;
    }
    return true;
}

int main () {
    int n;
    cin >> n;

    cout << isPalindrome(n) << endl;
    return 0;
}