#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> expression;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') expression.push(s[i]);
        else {
            if (s[i] == ')') {
                if (!expression.empty() && expression.top() == '(') expression.pop();
                else return false;
            }

            if (s[i] == ']') {
                if (!expression.empty() && expression.top() == '[') expression.pop();
                else return false;
            }

            if (s[i] == '}') {
                if (!expression.empty() && expression.top() == '{') expression.pop();
                else return false;
            }
        }
    }
    if (expression.size() != 0) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    cout << isValid(s) << endl;

    return 0;
}
