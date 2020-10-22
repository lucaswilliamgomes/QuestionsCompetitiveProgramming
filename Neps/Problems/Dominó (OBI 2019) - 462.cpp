#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, soma = 0;
    cin >> N;

    for (int i = 1; i <= N + 1; i++){
        soma += i;
    }
    cout << soma;
    return 0;
}