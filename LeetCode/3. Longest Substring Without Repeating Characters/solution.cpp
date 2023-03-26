#include <bits/stdc++.h>

using namespace std;

// two pointers
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last_seen;
    int start = 0, max_size = 0;
    for (int end = 0; end < s.size(); end++) {
        if (last_seen.count(s[end]) && last_seen[s[end]] >= start) {
            start = last_seen[s[end]] + 1;
        }

        last_seen[s[end]] = end;
        max_size = max(max_size, end - start + 1);
    }

    return max_size;
}


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
