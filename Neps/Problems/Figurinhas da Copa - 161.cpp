#include <bits/stdc++.h>

using namespace std;

bool contem (int num, vector <int> carimbadas) {
    for (int i = 0; i < carimbadas.size(); i++){
        if (num == carimbadas[i]) return true;
    }
    return false;
}

int main () {
    int total, carim, comp, aux;
    vector <int> carimbadas;
    set <int> compradas;

    cin >> total >> carim >> comp;
    for (int i = 0; i < carim; i++){
        cin >> aux;
        carimbadas.push_back(aux);
    }

    for (int i = 0; i < comp; i++){
        cin >> aux;
        compradas.insert(aux);
    }

    for (int it : compradas) {
        if (contem (it, carimbadas)) carim--;
    }
    cout << carim << endl;
    return  0;
}