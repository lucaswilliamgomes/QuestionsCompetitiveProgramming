#include <bits/stdc++.h>

using namespace std;

void findCombinations(int n, int openCount, int currentOpen, 
    string currentCombination, vector<string> &combinations) {
        if (openCount == n && currentOpen == 1) {
            currentCombination += ')';
            combinations.push_back(currentCombination);
            return;
        }

        if (currentOpen > 0) {
            currentCombination += ')';
            findCombinations(n, openCount, currentOpen - 1, currentCombination, combinations);
            currentCombination.pop_back();
        }

        if (openCount != n) {
            currentCombination += '(';
            findCombinations(n, openCount + 1, currentOpen + 1, currentCombination, combinations);
        }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    findCombinations(n, 1, 1, "(", ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<string> ans = generateParenthesis(n);

    for (auto it: ans) {
        cout << it << endl;
    }

    return 0;
}
