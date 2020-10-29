#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a < b and a < c){
        if (b<c){
            cout << 1 << endl << 2 << endl << 3 << endl;
        } else {
            cout << 1 << endl << 3 << endl << 2 << endl;
        }
    } else if (b < a and b < c){
        if (a<c){
            cout << 2 << endl << 1 << endl << 3 << endl;
        } else {
            cout << 2 << endl << 3 << endl << 1 << endl;
        }
    } else {
        if (b<a){
            cout << 3 << endl << 2 << endl << 1 << endl;
        } else {
            cout << 3 << endl << 1 << endl << 2 << endl;
        }
    }
    return 0;
}