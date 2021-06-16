#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int main(int argc, char const *argv[]){
    string expression;

    while(cin >> expression) {
        queue<char> l;
        int flag = 0;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '(') {
                flag++;
                l.push('(');
            } else if (expression[i] == ')') {
                flag--;
                if (flag < 0) break;
                l.pop();
                
            }
        }
        if (l.empty() and flag >= 0) {
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}
