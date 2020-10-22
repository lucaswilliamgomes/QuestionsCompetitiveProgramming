#include <bits/stdc++.h>

using namespace std;

int main () {
    string risada, risada_vogals, risada_copy;
    string vogais = "aeiou";
    int aux = 0;
    cin >> risada;

    for (int i = 0; i < risada.size(); i++){
        for (int y = 0; y < 5; y++){
            if(risada[i] == vogais[y]){
                risada_vogals.insert(aux, 1, risada[i]);
                aux++;
            }
        }
    }

    risada_copy = risada_vogals;
    reverse(risada_vogals.begin(), risada_vogals.end());

    if(risada_copy == risada_vogals) cout << 'S';
    else cout << 'N';
    return 0;
}