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
    int n;
    cin >> n;
    while (n--) {
        int ans = 0;
        string k;
        queue <char> p;
        cin >> k;
        for (int i = 0; i < k.length(); i++) {
            if (k[i] == '<') {
                p.push('<');
            } else if (k[i] == '>' and !p.empty()) {
                p.pop();
                ans++;
            }
        }        
        cout << ans << endl;
    }
    return 0;
}
