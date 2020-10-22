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

    ll n, aux, ans = 0;
    
    cin >> n;

    vector <ll> numbers;


    for (ll i = 0; i < n; i++){
        cin >> aux;
        numbers.push_back(aux);
    }   

    if ((numbers[n-1] * numbers[n-2] * numbers[n-3]) > (numbers[0] * numbers[1] * numbers[n-1]))
        ans = numbers[n-1] * numbers[n-2] * numbers[n-3];
    else   
        ans = numbers[0] * numbers[1] * numbers[n-1];

    cout << ans << endl;

    return 0;
}
