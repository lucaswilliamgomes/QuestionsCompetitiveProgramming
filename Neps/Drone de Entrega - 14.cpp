#include <bits/stdc++.h>

using namespace std;

void menor (vector <int> vetor){
    int index, menor = 110;

    for(int i = 0; i < vetor.size(); i++){
        if (vetor[i] < menor) {
            menor = vetor[i];
            index = i;
        }
    }
    vetor[index] = 110;
}

int main (){
    int aux, h, l, index, menor, maior, menor1 = 110, menor2 = 110;
    vector <int> dimens;

    for (int i = 0; i < 3; i++){
        cin >> aux;
        dimens.push_back(aux);
    }

    cin >> h >> l;

    for(int i = 0; i < dimens.size(); i++){
        if (dimens[i] < menor1) {
            menor1 = dimens[i];
            index = i;
        }
    }

    dimens[index] = 110;

    for(int i = 0; i < dimens.size(); i++){
        if (dimens[i] < menor2) {
            menor2 = dimens[i];
        }
    }

    menor1 = min(menor1, menor2);
    menor2 = max(menor1, menor2);

    menor = min(h, l);
    maior = max(h,l);

    if (menor1 <= menor and menor2 <= maior) cout << 'S' << endl;
    else cout << 'N' << endl;

    
    return 0;
}