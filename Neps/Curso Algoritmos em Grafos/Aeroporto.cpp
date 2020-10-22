#include <bits/stdc++.h>

using namespace std;

int pseudografo [105];
vector <int> maximo;

int main () {
    int A, V, u, t, maior = 0, cont = 1;


    
    
        cin >> A >> V;
        

        for (int i = 0; i < 105; i++){
            pseudografo[i] = 0;
        }

        for (int i = 0; i < V; i++){
            cin >> u >> t;
            pseudografo[u]++;
            pseudografo[t]++;
        }

        for (int i = 0; i < 105; i++){
            maior = max(pseudografo[i], maior);
        }
        
        for (int i = 0; i < 105; i++){
            if (pseudografo[i] == maior) maximo.push_back(i);
        }

        sort(maximo.begin(), maximo.end());

        cout << "Teste " << cont << endl;

        for (int i = 0; i < maximo.size(); i++){
            cout << maximo[i] << " ";
        }

        cout << endl;

        maximo.clear();

        cont++;
    

    return 0;
}