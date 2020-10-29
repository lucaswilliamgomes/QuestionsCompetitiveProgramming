#include <bits/stdc++.h>

using namespace std;

int n;
char f;
char matriz [505][505];

void fissura(int x ,int y){ 

    if (x < n-1){      
        if (matriz[x+1][y] <= f){
            cout << 'e' << endl;
            matriz[x+1][y] = '*';
            fissura (x+1, y);
        } else return;
    }

    if (y < n-1){
        if (matriz[x][y+1] <= f){
            matriz[x][y+1] = '*';
            fissura (x, y+1);
        } else return;
    }
    
    if (x > 0){
        if (matriz[x-1][y] <= f){
            matriz[x-1][y] = '*';
            fissura (x-1, y);
        } else return;
    }

    if (y > 0){
        if (matriz[x][y-1] <= f){
            matriz[x][y-1] = '*';
            fissura (x, y-1);
        } else return;
    }
    
}

int main () {
    cin >> n >> f;

    for (int i = 0; i < 505; i++){
        for (int j = 0; j <= 505; j++){
            matriz[i][j] = 'A';
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    matriz[0][0] = '*';

    fissura (0, 0);

    cout << endl;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matriz[i][j]; 
        }
        cout << endl;
    }

    return 0;
}