#include <bits/stdc++.h>

using namespace std;

int main () {
    string cifrada, crib;
    int ans = 0;
    cin >> cifrada >> crib;
    int tcifrada = cifrada.size();
    int tcrib = crib.size();

    for (int i = 0; i <= tcifrada - tcrib; i++){
        for (int j = 0; j < tcrib; j++){
            if (crib[j] == cifrada[i+j]) break;
            if (j == tcrib - 1) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}