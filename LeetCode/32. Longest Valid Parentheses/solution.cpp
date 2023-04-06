#include <bits/stdc++.h>

using namespace std;

// linear time and linear space
int longestValidParentheses(string s) {
    int size = s.size(), longestValidSubstring = 0;
    stack<int> noMatchIndexs;

    for (int i = 0; i < size; i++) {
        if (s[i] == '(') {
            noMatchIndexs.push(i);
        } else {
            if (noMatchIndexs.empty()) noMatchIndexs.push(i);
            else {
                if (s[noMatchIndexs.top()] == '(') {
                    noMatchIndexs.pop();
                } else {
                    noMatchIndexs.push(i);
                }
            }
        }
    }

    if (noMatchIndexs.empty()) longestValidSubstring = size;
    else {
        // Procurar a maior distancia de indices que não dão match na stack
        int l = 0, r = size;

        while (!noMatchIndexs.empty()) {
            l = noMatchIndexs.top(); 
            noMatchIndexs.pop();

            longestValidSubstring = max(longestValidSubstring, r - l - 1);
            r = l;
        }

        longestValidSubstring = max(longestValidSubstring, l);
    }

    return longestValidSubstring;
}


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    cout << longestValidParentheses(s) << endl;
  
    return 0;
}



