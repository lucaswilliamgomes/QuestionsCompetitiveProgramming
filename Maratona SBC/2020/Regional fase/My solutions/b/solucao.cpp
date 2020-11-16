#include <bits/stdc++.h>

using namespace std;

int mapa[15][15];

int main () {

    // Colocando 0 em todos os lugares da matrix
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15;j++){
            mapa[i][j]=0;
        }
    }
    int n, d, r, l, c;
    char ans = 'Y';
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> d >> l >> r >> c;
        if (d == 0){
            for (int i = 0; i <= l-1; i++){
                if (c+i > 10){
                    ans = 'N';
                    continue;
                } 
                mapa[r][c+i]++;
            }
        } else {
            for (int i = 0; i <= l-1; i++){
                if (r+i > 10){
                    ans = 'N';
                    continue;
                }
                mapa[r+i][c]++;
            }
        }
    }

    if (ans == 'N') {
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10;j++){
            if (mapa[i][j] > 1) {
                ans = 'N';
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}