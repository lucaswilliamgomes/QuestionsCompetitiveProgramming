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
    int n, ans = 0;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        if (k == 2 or k == 3) ans++;
    }
    cout << ans << endl;
    return 0;
}
