#include <bits/stdc++.h>

using namespace std;

int main (){    
    int a,b,c,d, pointa, pointb;
    cin >> a >> b >> c >> d;

    if (a==b) pointa = 2 * (a+b);
    else if (a == b+1 or b == a+1) pointa = 3 * (a+b);
    else pointa = a + b;

    if (c==d) pointb = 2 * (c+d);
    else if (c == d+1 or d == c+1) pointb = 3 * (c+d);
    else pointb = d + c;

    

    if (pointa > pointb) cout << "Lia" << endl;
    else if (pointa == pointb) cout << "empate" << endl;
    else if (pointa < pointb) cout << "Carolina" << endl;
    

    return 0;
}