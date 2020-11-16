#include <bits/stdc++.h>

using namespace std;

int j, f;
vector <int> grafo[110];

bool teste () {
    for (int i = 0; i < f; i++){
        
    }


    return false;
}

int main () {
    
    cin >> j >> f;
    for (int i = 0, u, v; i < f; i++){
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }




    return 0;
}