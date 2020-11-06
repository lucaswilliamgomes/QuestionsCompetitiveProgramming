#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int n, k, pai[MAXN];

int find (int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y)  {
    pai[find(x)] = find(y);
}

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) pai[i] = i;

    for (int i = 0, x, y; i < k; i++){
        char operacao;
        cin >> operacao >> x >> y;
        if (operacao == 'F')join (x, y); 
        else cout << (find(x) == find (y) ? 'S' : 'N') << endl;
    }
    return 0;
}