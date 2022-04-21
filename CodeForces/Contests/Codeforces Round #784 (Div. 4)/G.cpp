#include <bits/stdc++.h>
#define MAXNM 55
using namespace std;

char mat[MAXNM][MAXNM];

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == '*') {
                        if (i+1 < n && mat[i+1][j] == '.') {
                            flag = true;
                            mat[i+1][j] = '*';
                            mat[i][j] = '.';
                        }
                    }
                }
            }
        }
        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j];
            }
            cout << endl;
        }

    }

    return 0;
}