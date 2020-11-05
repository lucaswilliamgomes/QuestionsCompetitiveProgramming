#include <bits/stdc++.h>

using namespace std;

queue <char> times;

int main () {

    for (char i = 'A'; i <= 'P'; i++){
        times.push(i);
    }   

    for (int i = 0, a, b; i < 15; i++){
        cin >> a >> b;
        char win;
        if (a > b) {
            win = times.front();
            times.pop();
            times.pop();
            times.push(win);
          
        } else {
            times.pop();
            win = times.front();
            times.pop();
            times.push(win);
         
        }
    }

    cout << times.front() << endl;
    return 0;
}