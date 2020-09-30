#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

void staircase(int n) {
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (j <= (n - i)) cout << ' ';
            else cout << '#';
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    staircase(n);
    return 0;
}
