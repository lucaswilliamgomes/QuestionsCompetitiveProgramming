#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, aux;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (aux <= 1399) {
            cout << "Division 4" << endl;
        } else if (aux >= 1400 && aux <= 1599) {
            cout << "Division 3" << endl;
        } else if (aux >= 1600 && aux <= 1899) {
            cout << "Division 2" << endl;
        } else {
            cout << "Division 1" << endl;
        }
    }

    return 0;
}