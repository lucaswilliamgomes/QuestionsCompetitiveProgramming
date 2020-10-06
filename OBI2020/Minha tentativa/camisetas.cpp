#include <bits/stdc++.h>

using namespace std;

int main () {
    int premiados, aux, auxp, auxm, p, m;

    cin >> premiados;
    auxp = 0;
    auxm = 0;
    for (int i = 0; i < premiados; i++) {
        cin >> aux;
        if (aux == 1) auxp++;
        if (aux == 2) auxm++;
    } 

    cin >> p >> m;

    if (p >= auxp && m >= auxm) cout << 'S' << endl;
    else cout << 'N' << endl;

    return 0;
}