#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    int n, m;
    cin >> n, m;

    bool flag = true;
    int ant;
    int atual;
    
    cin >> ant;

    for (int i = 1; i < n; i++) {
        cin >> atual;
        if (atual - ant > m) flag = false;
        ant = atual;
    }

    if (42195 - atual > m) {
        flag = false;
    }
    

    if (flag) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}