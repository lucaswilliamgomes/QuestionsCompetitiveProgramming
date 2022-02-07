#include <bits/stdc++.h>

using namespace std;

int main () {
    string number;
    cin >> number;
    for (int i = number.size() - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if ((number[i] - '0') < (number[j] - '0') && !(j == 0 && number[i] == '0')) {
                swap(number[i], number[j]);
                cout << number << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}