#include <bits/stdc++.h>

using namespace std;

int main () {
    int l, c;
    cin >> l >> c;

    int total2 = ((l-1) * 2) + ((c-1) * 2);
    int total1 = c * l + (c-1) * (l-1);
    
    cout << total1 << endl << total2 << endl; 
}