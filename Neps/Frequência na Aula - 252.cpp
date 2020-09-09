#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, aux;
    set<int> frequency;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> aux;
        frequency.insert(aux);
    }
    cout << frequency.size();
    return 0;
}