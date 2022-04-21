#include <bits/stdc++.h>

using namespace std;

int main () {

    int t, n, aux;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        int cont = 0;
        int parity = ar[cont] % 2;
        bool flag = true;
        while (cont < n) {
            //cout << ar[cont] << " " << ar[cont] % 2 << endl;
            if (ar[cont] % 2 != parity) flag = false;
            cont += 2;
        }

        if (!flag) {
            cout << "NO" << endl;
            continue;
        }

        cont = 1;
        parity = ar[cont] % 2;

        while (cont < n) {
            if (ar[cont] % 2 != parity) flag = false;
            cont += 2;
        }

        if (!flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }

    return 0;
}