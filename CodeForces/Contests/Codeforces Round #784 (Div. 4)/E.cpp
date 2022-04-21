#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<ll> ar(n);

    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        ar[i] = (int) aux[0] + (int) aux[1];
    }

    for (int i = 0; i < n; i++) {
        cout << ar[i] << endl;
    }

}