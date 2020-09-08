#include <bits/stdc++.h>

using namespace std;

bool is_pair(int num) {return (num % 2 == 0);}

int main () {
    int l, c;
    cin >> l >> c;
    if (is_pair(l) == is_pair(c)) cout << 1;
    else cout << 0;
    return 0;
}