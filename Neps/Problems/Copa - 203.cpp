#include <bits/stdc++.h>

using namespace std;

int main () {
    float a, b;

    cin >> a >> b;
    
    if (ceil(a/2) == ceil(b/2)) cout << "oitavas" << endl;
    else if (ceil(a/4) == ceil(b/4)) cout << "quartas" << endl;
    else if (ceil(a/8) == ceil(b/8)) cout << "semifinal" << endl;
    else cout << "final" << endl; 
    return 0;
}