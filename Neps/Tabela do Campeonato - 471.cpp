#include <bits/stdc++.h>

using namespace std;

int main () {
    int j, p, v, e ,d;
    cin >> j >> p >> v >> e >> d;


    if (j == -1){

        if (p == -1){
           p = (v*3) + (e);
        } else if (v == -1) {
           v = (p - e) / 3;
        } else if (e == -1) {
           e = p - (v * 3);
        } 

        j = v + d + e;

        cout << j << " " << p << " " << v << " " << e << " " <<  d;
        return 0; 

    } 

    if (p == -1) {
        if (v == -1){
            v = j - e - d;
        } else if (e == -1){
            e = j - v - d;
        } else if (d == -1) {
            d = j - v - e; 
        }
        p = (v * 3) + e;
        cout << j << " " << p << " " << v << " " << e << " " << d;
        return 0;  
    }

    if (v == -1){
        if (e == -1){
            e = ((3 * j) - (3 * d)) / 2 * p;
        }
        if (d == -1){
            d = j - v - e; 
        }
        v = j - e - d; 
        cout << j << " " << p << " " << v << " " << e << " " << d;
        return 0;  
    }

    if (e == -1){
        e = p - (v * 3);
        if (d == -1){
            d = j - v - e;  
        }
        cout << j << " " << p << " " << v << " " << e << " " << d;
        return 0;
    }
    if (d == -1){
        d = j - v - e;  
        cout << j << " " << p << " " << v << " " << e << " " << d;
        return 0;
    }
}