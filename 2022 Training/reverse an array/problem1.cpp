#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int ar[MAXN];
int t, n;
void reverseAr() {
    int aux;
    for (int i = 0; i < n/2; i++) {
        aux = ar[i];
        ar[i] = ar[n-1-i];
        ar[n-1-i] = aux;
    }
}


int main () {
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        reverseAr();

        for(int i = 0; i < n; i++) {
            cout << ar[i] << " ";
        }
        cout << endl;
    }

    return 0;
}