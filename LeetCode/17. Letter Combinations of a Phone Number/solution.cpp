#include <bits/stdc++.h>

using namespace std;

void searchNewCombination(string &digits, int indexDigit, int currentLetterIndex, 
    vector<string> &currentAns, string currentCombination, map<char, vector<char>> &mp) {

    currentCombination += mp[digits[indexDigit]][currentLetterIndex];

    if (indexDigit == digits.size() - 1) {
        // cout << currentCombination << endl;
        currentAns.push_back(currentCombination);
        return;
    }

    for (int i = 0; i < mp[digits[indexDigit + 1]].size(); i++) {
        searchNewCombination(digits, indexDigit + 1, i, currentAns, currentCombination, mp);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c' }},
        {'3', {'d', 'e', 'f' }}, 
        {'4', {'g', 'h', 'i' }}, 
        {'5', {'j', 'k', 'l' }}, 
        {'6', {'m', 'n', 'o' }}, 
        {'7', {'p', 'q', 'r', 's' }}, 
        {'8', {'t', 'u', 'v' }}, 
        {'9', {'w', 'x', 'y', 'z' }}
    };
    
    for (int i = 0; i < mp[digits[0]].size(); i++) {
        searchNewCombination(digits, 0, i, ans, "", mp);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    vector<string> ans = letterCombinations(s);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
