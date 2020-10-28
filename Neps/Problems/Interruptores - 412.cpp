#include <bits/stdc++.h>

using namespace std;

vector <int> interruptores[1020];
bool lampadas [1020];
int inter, lamp, ans = 0;

bool verifica(){
    for (int i = 0; i <= lamp; i++){
        if (lampadas[i]) return false;
    }

    return true;
}

int main () {
    int acesas, aux;
    cin >> inter >> lamp;

    // Acedendo lampadas iniciais
    cin >> acesas;
    for (int i = 0; i < acesas; i++){
        cin >> aux;
        lampadas[aux] = true;
    }
    
    // Setando os interruputores 
    int k;
    for (int i = 1; i <= inter; i++){
        cin >> aux;
        for (int j = 1; j <= aux; j++){
            cin >> k;
            interruptores[i].push_back(k);
        }
    }

    int ciclos = 0;
    for (int i = 1; i <= inter; i++){
        for (int j = 0; j < interruptores[i].size(); j++){
            if (lampadas[interruptores[i][j]]) lampadas[interruptores[i][j]] = false ;
            else lampadas[interruptores[i][j]] = true;
        }
        ans++;
        if (verifica()) break;
        
        if (i == inter){
            i = 0;
            ciclos++;
        } 
        if (ciclos > 5) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}