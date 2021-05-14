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
        string str;
        int k;
        cin >> str >> k;
        for (int i = 0; i < str.length(); i++) {
            if (int(str[i]) - k < 65) {
                str[i] = 90 - (k - (int(str[i]) - 64));
            } else str[i] -= k;       
        }
        cout << str << endl;
    }
    return 0;
}
