#include <bits/stdc++.h>

using namespace std;

int main (){
    int num1, num2, num3;

    cin >> num1 >> num2 >> num3;

    if (num1 == num2 or num1 == num3) {
        if (num1 == num2) cout << num3 << endl;
        else cout << num2 << endl;
    } else cout << num1 << endl;

    return 0;
}