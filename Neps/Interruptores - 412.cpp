#include <bits/stdc++.h>

using namespace std;

bool verifica (vector <bool> lampadas) {

    for (bool it : lampadas){
        if (!it) return false;
    }

    return true;
}

int main () {
    int totalint, totallamp;
    cin >> totalint >> totallamp;

    
    vector <int> interruptores[1020];
    
    int l, apertar, aux, aux2, ans = 0;
    cin >> l;

    vector <bool> lampadas(totallamp);

    for (int i = 0; i < l; i++){
        cin >> aux;
        lampadas[aux] = true;
    }

    for (int i = 1; i <= totalint; i++){
        cin >> aux;
        for (int j = 1; j <= aux; j++){
            cin >> aux2;
            interruptores[i].push_back(aux2);
        }
    }

    //while (!verifica(lampadas)){
        for (int i = 1; i <= totalint; i++){
            for (int j = 0; j < interruptores[i].size(); j++){

                apertar = interruptores[i][j];
                if(lampadas[apertar] == true) lampadas[apertar] = false;
                else lampadas[apertar] = false;
                ans++;

            }  
            if (i == totalint) {
                cout << ans << endl;
                return 0;
            }
        }   
    //}

    cout << ans << endl;
    return 0;
}