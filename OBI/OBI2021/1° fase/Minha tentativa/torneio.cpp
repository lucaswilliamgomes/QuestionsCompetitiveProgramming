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
    char resultado;
    int v = 0;

    for (int i = 0; i < 6; i++) {
        cin >> resultado;
        if (resultado == 'V') v++;
    }

    if (v >= 5) {
        cout << "1" << endl;
    } else if (v >= 3) {
        cout << "2" << endl;
    } else if (v >= 1) {
        cout << "3" << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
