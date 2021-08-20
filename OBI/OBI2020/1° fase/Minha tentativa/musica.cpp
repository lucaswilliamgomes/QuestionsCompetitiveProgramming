#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ll quant_amigos, quant_musicas, musica_comp, aux, aux2;
    vector < vector <int> > escolhas; 
    vector <int> adoradas;
    cin >> quant_amigos >> quant_musicas >> musica_comp;
    ll ans = 0;

    for (ll i = 0; i < quant_amigos; i++) {
        cin >> aux >> aux2;
        escolhas[i].push_back(aux);
        adoradas.push_back(aux);
        escolhas[i].push_back(aux2);
    }

    sort(escolhas.begin(), escolhas.end());
    


        for (ll j = 0; j < quant_amigos; j++){
            if (musica_comp == escolhas[j][1]) {
                musica_comp = escolhas[j][1];
                ans++;
                break;
            }
        }
     
    

    if (ans == quant_amigos) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}