#include <bits/stdc++.h>

using namespace std;

int main () {
    int range;
    cin >> range;
    if (range <= 800) cout << 1;
    else if(range > 800 and range <=1400) cout << 2;
    else if(range > 1400 and range <=2000) cout << 3;

    return 0;
}