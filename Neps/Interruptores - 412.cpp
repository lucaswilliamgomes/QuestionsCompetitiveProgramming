#include <bits/stdc++.h>

using namespace std;

vector <int> interruptores[1020];

int main () {
    
    cin >> inter >> lamp;
    bool acesas [lamp + 5];

    for (int i = 1; i <= lamp; i++){
        acesas[i] = false;
    }

    cout << verifica(acesas) << endl;
    cin >> ligadas;

    for (int i = 0; i < ligadas; i++){
        cin >> aux;
        acesas[aux] = true;
    }



    return 0;
}