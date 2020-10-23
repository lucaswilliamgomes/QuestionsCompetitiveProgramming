#include <bits/stdc++.h>

using namespace std;

vector <int> grafo[100005];



int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        grafo[v].push_back(u);
    }





    return 0;
}