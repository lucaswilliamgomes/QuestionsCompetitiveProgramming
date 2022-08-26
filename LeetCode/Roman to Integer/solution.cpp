#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()

using namespace std;

int romanToInt(string s) {
    int ans = 0, pivo = 0;

    map<char, int> romanos = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    vector<char> romans = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1) {
            if (find(romans.begin(), romans.end(), s[i]) - romans.begin() < find(romans.begin(), romans.end(), s[i + 1]) - romans.begin()) {
                pivo += romanos[s[i]];
            } else {
                ans += romanos[s[i]] - pivo;
                pivo = 0;
            }
        } else {
            ans += romanos[s[i]] - pivo;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    string a;
    cin >> a;
    cout << romanToInt(a) << endl;
    return 0;
}
