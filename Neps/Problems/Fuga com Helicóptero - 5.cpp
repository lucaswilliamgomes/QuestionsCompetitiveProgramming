#include <bits/stdc++.h>

using namespace std;

int main (){
    int h, p, f, d;
    cin >> h >> p >> f >> d;

    if (d == -1) {
        while (true){
            
            if (f == p) {
                cout << "N" << endl;
                return 0;
            }
            if (f == h) {
                cout << "S" << endl;
                return 0;
            }
            if(f == 0) {
                f = 15;
                continue;
            };
            f--;
        }
    } else {
        while (true){
            
            if (f == p) {
                cout << "N" << endl;
                return 0;
            }
            if (f == h) {
                cout << "S" << endl;
                return 0;
            }
            if(f == 15){
                f = 0;
                continue;
            }
            
            f++;
        }
    }

    return 0;
}