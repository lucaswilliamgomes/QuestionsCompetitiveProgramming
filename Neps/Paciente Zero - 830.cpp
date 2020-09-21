#include <bits/stdc++.h>

using namespace std;


int main () {
    int total, cadeias;
    int infector, pessoas, pessoa, infectado;
    cin >> total >> cadeias;

    vector <int> dados[1000];

    for (int i = 0; i < cadeias; i++){
        cin >> infector >> pessoas;
        for (int j = 0; j < pessoas; j++){
            cin >> pessoa;
            dados[pessoa-1].push_back(infector);
            
        }
    }
    
    for (int i = 0; i < total; i++){
        if (dados[i].size() == 0) cout << i + 1 << endl;
    }
    return 0;
}