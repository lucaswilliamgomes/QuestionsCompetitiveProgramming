#include <bits/stdc++.h>

using namespace std;

int main () {
    int k, l;
    queue<int> fila;

    cin >> k;
    cin >> l;

    for (int i = 1; i <= 16; i++){
        fila.push(i);
    }

    for (int i = 0; i < 8; i+=2){
        
        cout << fila.front();
        fila.pop();


    }

    

    return 0;
}