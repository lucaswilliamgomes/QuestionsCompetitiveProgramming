#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> t;

    vector<int> a = {1, 2};

    t.push_back(a);

    for (auto it : t) {
        for (int i = 0; i < it.size(); i++) {
            cout << it[i] << " ";
        }
    }

    cout << endl;
    
    return 0;
}
