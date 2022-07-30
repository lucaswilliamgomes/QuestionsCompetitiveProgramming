#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int,int> ans;
    int n;
    cin >> n;

    while (n--) {
        int aux;
        cin >> aux;
        ans[aux]++;
    }

    for (auto it: ans) {
        if (it.second == 1) {
            cout << it.first << endl;
            return 0;
        }
    }
   

    return 0;
}
