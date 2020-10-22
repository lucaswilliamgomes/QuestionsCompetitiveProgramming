#include <bits/stdc++.h>

using namespace std;

bool ja_existe (vector<int> vetor, int element) {
    bool aux = false;
    for (int i = 0; i < vetor.size(); i++){
        if (element == vetor[i]) return aux = true;
    }
    return aux;
}

int main () {
    int cartelas, quant, range, aux;

    cin >> cartelas >> quant >> range;

    vector < vector <int> > all;
    vector< int > bingo;

    for (int i = 0; i < cartelas; i++) {
        all.push_back(bingo);
        for (int y = 0; y < quant; y++) {
            cin >> aux;
            all[i].push_back(aux);
        }
    }


    /*
    for (int i = 0; i < cartelas; i++) {
        for (int y = 0; y < quant; y++) {
            cout << all[i][y] << " ";
        }
        cout << endl;
    }*/



    for (int i = 0; i < range; i++){
        cin >> aux;
        for (int y = 0; y < cartelas; y++) {
            if(ja_existe(all[y], aux)){
                all[y].erase(remove(all[y].begin(), all[y].end(), aux), all[y].end());
            } else continue;

            if (all[y].empty()) {
                if(!ja_existe(bingo, y)) bingo.push_back(y);
            }
        }

        if (bingo.size() != 0) break;
    }


    for (int i = 0; i < bingo.size(); i++){
        cout << bingo[i] + 1 << " ";
    }


    return 0;
}