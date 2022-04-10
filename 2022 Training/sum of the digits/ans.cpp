#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(int num) {
    int ans = 0;
    while (num != 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main () {
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
    return 0;
}
