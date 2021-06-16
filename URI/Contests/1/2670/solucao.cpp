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
    int a1, a2, a3, sum1, sum2, sum3;
    cin >> a1 >> a2 >> a3;
    sum1 = (a2 * 2) + (a3 * 4);
    sum2 = (a1*2) + (a3 * 2);
    sum3 = (a1*4) + (a2 * 2);
    int aux = min(sum2, sum1);
    cout << min(aux, sum3) << endl;
    return 0;
}
