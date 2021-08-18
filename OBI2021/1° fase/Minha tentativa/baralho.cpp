#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int main(int argc, char const *argv[]){
    vector<int> copas;
    vector<int> espadas;
    vector<int> ouros;
    vector<int> paus;

    string cod, aux;
    cin >> cod;
    int num;
    char naipe;

    bool repetiuC = false, repetiuE = false, repetiuU = false, repetiuP = false; 

    while (!cod.empty()) {
        naipe = cod.back();
        cod.pop_back();
        aux.push_back(cod[cod.length()-2]);
        aux.push_back(cod[cod.length()-1]);
        cod.pop_back();
        cod.pop_back();
        num = stoi(aux);
        aux.clear();

        if (naipe == 'C') {
            for (auto it : copas) {
                if (num == it) {
                    repetiuC = true;
                    break;
                }
            }
            if (!repetiuC) {
                copas.push_back(num);
            }
        }

        else if (naipe == 'E') {
            for (auto it : espadas) {
                if (num == it) {
                    repetiuE = true;
                    break;
                }
            }
            if (!repetiuE) {
                espadas.push_back(num);
            }
            
        }

        else if (naipe == 'U') {
            for (auto it : ouros) {
                if (num == it) {
                    repetiuU = true;
                    break;
                }
            }
            if (!repetiuU) {
                ouros.push_back(num);
            }
        } 
        
        else if (naipe == 'P') {
            for (auto it : paus) {
                if (num == it) {
                    repetiuP = true;
                    break;
                }
            }
            if (!repetiuP) {
                paus.push_back(num);
            }
        }   
    }


    if (repetiuC) {
        cout << "erro" << endl;
    } else {
        cout << 13 - copas.size() << endl;
    }

    if (repetiuE) {
        cout << "erro" << endl;
    } else {
        cout << 13 - espadas.size() << endl;
    }

    if (repetiuU) {
        cout << "erro" << endl;
    } else {
        cout << 13 - ouros.size() << endl;
    }

    if (repetiuP) {
        cout << "erro" << endl;
    } else {
        cout << 13 - paus.size() << endl;
    }
    
    return 0;
}
