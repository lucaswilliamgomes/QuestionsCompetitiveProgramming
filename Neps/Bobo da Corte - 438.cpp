#include <bits/stdc++.h>

using namespace std; 

int main () {
    vector <int> votos;
    int n, aux, bobo;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> aux;
        if (i == 0) bobo = aux;
        votos.push_back(aux);
    }

    sort(votos.begin(), votos.end());

    if (votos[n-1] == bobo) cout << "S" << endl;
    else cout << "N" << endl;
    return 0;
}