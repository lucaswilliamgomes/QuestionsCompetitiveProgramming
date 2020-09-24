#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, aux;
    cin >> n;

    vector <int> tam;

    for (int i = 0; i < n; i++){
        cin >> aux;
        tam.push_back(aux);
        
    }

    for (int i = 1; i < (n-1); i++){
        if ((tam[i] < tam[i-1] and tam[i] < tam[i+1])) {
            cout << 'S' << endl;
            return 0;
        }
    }
    cout << 'N' << endl;
    return 0;
}