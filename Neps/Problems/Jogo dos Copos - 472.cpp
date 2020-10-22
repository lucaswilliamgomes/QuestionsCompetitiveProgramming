#include <bits/stdc++.h>

using namespace std;


int main () {
    int quant, mov;
    string pos = "ABC";
    char ans, aux;

    cin >> quant >> ans;

    for (int i = 0; i < quant; i++){
        cin >> mov;
        if (mov == 1) {
            aux = pos[0];
            pos[0] = pos[1];
            pos[1] = aux;
        } else if (mov == 2) {
            aux = pos[1];
            pos[1] = pos[2];
            pos[2] = aux;
        } else if (mov == 3) {
            aux = pos[0];
            pos[0] = pos[2];
            pos[2] = aux;
        }
    }

    for (int i = 0; i < 3; i++){
        //cout << pos[i] << endl;
        if (pos[i] == ans) aux = i + 1; 
    }

    //cout << ans << endl;

    if (aux == 1) cout << 'A' << endl;
    else if (aux == 2) cout << 'B' << endl;
    else if (aux == 3) cout << 'C' << endl;
    return 0;
}