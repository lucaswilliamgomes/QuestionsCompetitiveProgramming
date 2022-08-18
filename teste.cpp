#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> ar;
    ar.push(1);
    ar.push(2);
    ar.push(2);
    ar.push(4);
    ar.push(5);

    for (auto it : ar) {
        cout << it << endl;
    }
    
    return 0;
}
