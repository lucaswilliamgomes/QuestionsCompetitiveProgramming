#include <bits/stdc++.h>
#define INF 2000000020LL
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

string removeDuplicates(string s) {
    stack<char> str;
    string ans;
    for (auto c: s) {
        if (str.empty()) {
            str.push(c);
        } else {
            if (str.top() == c) {
                str.pop();
            } else {
                str.push(c);
            }
        }
    }
    
    while (true){
        if (str.size() == 0) break;
        ans.push_back(str.top());
        str.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[]){
    string s;
    cin >> s;
    cout << removeDuplicates(s) << endl;
    return 0;
}

