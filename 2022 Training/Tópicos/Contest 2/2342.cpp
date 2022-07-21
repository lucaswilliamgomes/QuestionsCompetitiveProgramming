#include <bits/stdc++.h>

using namespace std;

int main () {
    int a, b, t;
    char str;
    cin >> t;
    cin >> a >> str >> b;

    if (str == '+') {
        if (a + b <= t) {
            cout << "OK" << endl;
        } else {
            cout << "OVERFLOW" << endl;
        }
    } else {
        if (a * b <= t) {
            cout << "OK" << endl;
        } else {
            cout << "OVERFLOW" << endl;
        }
    }




    return 0;
}