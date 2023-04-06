#include <bits/stdc++.h>

using namespace std;

string findStringWithMoreCaractereRepeated(vector<string> &strs) {
    string ans;
    int maxCaractererRepeatedCount = 0;
    for (int i = 0; i < strs.size(); i++) {
        unordered_map<char, int> freqCaracters;
        for (int j = 0; j < strs[i].size(); j++) {
            freqCaracters[strs[i][j]]++;
            if (freqCaracters[strs[i][j]] > maxCaractererRepeatedCount) {
                maxCaractererRepeatedCount = freqCaracters[strs[i][j]];
                ans = strs[i];
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << findStringWithMoreCaractereRepeated(strs) << endl;
  
    return 0;
}
