#include <bits/stdc++.h>

using namespace std;

map<int,int> socks;

int main () {

    int n;
    cin >> n;
    int ans = 0;
    int max_ = 0;
    n = 2 * n;
    while(n--) {
        int aux;
        cin >> aux;
        socks[aux]++;
        if (socks[aux] == 2) {
            ans--;
            socks[aux] = 0;
        } else {
            ans++;
        }

        max_ = max(max_, ans);    
    }

    cout << max_ << endl;

    return 0;
}