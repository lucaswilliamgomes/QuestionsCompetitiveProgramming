#include <bits/stdc++.h>

using namespace std;

vector <string> P;

int main () {
    int n;
    string aux;

    cin >>  n;

    for (int i = 0; i < n; i++){
        cin >> aux;
        P.push_back(aux);
    }

    for (int i = 0; i < n; i++){

        stack <char> ordem;

        for(int j = 0; j < P[i].size(); j++){
            if (P[i][j] == '{' or P[i][j] == '[' or P[i][j] == '('){
                ordem.push(P[i][j]);
            } else if (P[i][j] == '}' or P[i][j] == ']' or P[i][j] == ')') {

                // Verifica de estar vazio, se estiver é por que deu ruim
                if (ordem.empty()){
                    cout << 'N' << endl;
                    break;
                }

                if (P[i][j] == '}' and ordem.top() == '{') ordem.pop();
                else if (P[i][j] == ']' and ordem.top() == '[') ordem.pop();
                else if (P[i][j] == ')' and ordem.top() == '(') {
                    ordem.pop();
                    
                }
                else {
                    cout << 'N' << endl;
                    break;
                }
            }

            if (j == P[i].size() - 1 and ordem.empty()) cout << 'S' << endl;
            if (j == P[i].size() - 1 and !ordem.empty()) cout << 'N' << endl;
        }
    }

    return 0;
}