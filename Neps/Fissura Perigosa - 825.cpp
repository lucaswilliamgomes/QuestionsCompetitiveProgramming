#include <bits/stdc++.h>

using namespace std;

int main () {
    int rc, force;

    cin >> rc >> force;
    int num = 918;
    vector <string> lines;
    int matrix [rc][rc];
    
    for (int i = 0; i < rc; i++){
        cin >> lines[i];
    }

    for (int i = 0; i < rc; i++){
        for (int y = 0; y < rc; y++){
            
        }
    }
    




    if (matrix[0][0] <= force) matrix[0][0] = '*'; 

    for (int i = 0; i < rc; i++){
        for (int y = 0; y < rc; y++){
            cout << matrix[i][y];
        }
        cout << endl;
    }

    return 0;
}