#include <bits/stdc++.h>

using namespace std;

int main () {
    int doces, x, y, z, ans = 0;
    vector <int> poke;
    cin >> doces >> x >> y >> z;
    poke.push_back(x);
    poke.push_back(y);
    poke.push_back(z);

    sort (poke.begin(), poke.end());

    for (int i = 0; i < 3; i++){
        if (poke[i] <= doces) {
            ans++;
            doces-=poke[i];
        } else break;
    }

    cout << ans << endl;
    return 0;
}