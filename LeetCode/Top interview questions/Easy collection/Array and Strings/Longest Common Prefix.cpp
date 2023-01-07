#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    int smallerSize = INT32_MAX;

    for (int i = 0; i < strs.size(); i++) {
        smallerSize = min(smallerSize, (int)strs[i].size());
    }


    for (int i = 0; i < smallerSize; i++) {
        ans.push_back(strs[0][i]);
        for (int j = 0; j < strs.size(); j++) {
            if (strs[j][i] != ans[i]) {
                ans.pop_back();
                return ans;
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> words;
    while (n--) {
        string ex;
        cin >> ex;
        words.push_back(ex);
    }

    cout << longestCommonPrefix(words) << endl;

    return 0;
}
