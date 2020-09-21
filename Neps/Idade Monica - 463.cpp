#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int monica, son1, son2, son3, old;
    cin >> monica >> son1 >> son2;
    son3 = monica - (son1 + son2);
    old = max(son1, son2);
    old = max(old, son3);
    cout << old << endl;
    return 0;
}
