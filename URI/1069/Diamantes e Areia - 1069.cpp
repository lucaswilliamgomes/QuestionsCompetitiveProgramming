#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    string escavacao;
    
    int aux = 0;
    int ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> escavacao;

        for (int j = 0; j < escavacao.size(); j++){
    
            if (escavacao[j] == '<') {
                aux++;
            } else if (escavacao[j] == '>'){
                aux--;
                if (aux > 0) ans++;
            }
        }

        cout << ans << endl;
        ans = 0;
        aux = 0; 
    }

    return 0;
}


