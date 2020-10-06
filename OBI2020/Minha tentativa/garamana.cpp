#include <bits/stdc++.h>

using namespace std;

bool quant (char letra, vector <char> palavra, int quantidade) {
    int quanti = 0;
    for (int i = 0; i < palavra.size(); i++){
        if(palavra[i] == letra) quanti++; 
    }
    if (quantidade == quanti) return true;
    else return false; 
}

bool verifica (vector <char> palavra, vector <char> anagrama) {
    bool ans = true;
    vector <char> asteriscos;
    int quantidade = 0;
    int aux = 0;

    for (int i = 0; i < palavra.size(); i++){
        for (int j = 0; j < palavra.size(); j++){
            if(palavra[i] == palavra[j]){
                quantidade++;
            }
        }
        if (!quant(palavra[i], anagrama, quantidade)) {
            anagrama[aux] = palavra[i];
            aux++;
        }
        quantidade = 0;
    }

    sort (anagrama.begin(), anagrama.end());
    /*for (int i = 0; i < palavra.size(); i++){
        cout << anagrama[i];
    }
    cout << endl;

    for (int i = 0; i < palavra.size(); i++){
        cout << palavra[i];
    }*/

    for (int i = 0; i < palavra.size(); i++){
        if (palavra[i] != anagrama[i]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main () {
    string palavra, anagrama;
    vector <char> auxpalavra;
    vector <char> auxanagrama;

    cin >> palavra >> anagrama;

    for (int i = 0; i < palavra.size(); i++){
        auxpalavra.push_back(palavra[i]);
    }
    sort (auxpalavra.begin(), auxpalavra.end());

    for (int i = 0; i < palavra.size(); i++){
        auxanagrama.push_back(anagrama[i]);
    }
    sort (auxanagrama.begin(), auxanagrama.end());

    if (verifica (auxpalavra, auxanagrama)) {
        cout << 'S' << endl;  
    } else cout << 'N' << endl; 

    return 0;
}
