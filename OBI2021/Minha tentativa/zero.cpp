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
    int N, aux, ans = 0;
    vector<int> numbers;
    cin >> N;

    while (N--) {
        cin >> aux;
        if (aux != 0) {
            numbers.emplace_back(aux);
        } else {
            numbers.pop_back();
        }
    }

    for (int it : numbers){
        ans += it;
    }
    
    cout << ans << endl;
    return 0;
}
