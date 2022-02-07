#include <bits/stdc++.h>

using namespace std;

int grid[20][20];

int main () {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if (d == 0) {
            for (int i = c; i <= c + l - 1; i++) {
                grid[r][i] += 1;
            } 
        } else {
            for (int i = r; i <= r + l - 1; i++) {
                grid[i][c] += 1;
            }
        }
    }

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++) {
            if (grid[i][j] > 1 || ((i > 10 || j > 10) && (grid[i][j] != 0))) {
                cout << "N" << endl;
                return 0;
            }
        }
    }

    cout << "Y" << endl;

    return 0;
}