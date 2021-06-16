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
    string msg, crib;
    bool flag = false;
    int ans = 0;
    cin >> msg >> crib;

    for(int i = 0; i < msg.length() - (crib.length()-1); i++) {
        flag = false;
        for(int j = 0; j < crib.length(); j++) {
            if (msg[i+j] == crib[j]) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        else ans++;
    }

    cout << ans << endl;

    
    return 0;
}
