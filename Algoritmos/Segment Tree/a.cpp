#include <bits/stdc++.h>
#define MAXN 2000020
using namespace std;

int t[MAXN*4];

void build (int i, int l, int r) {
    // Nó folha
    if (l == r) {
        t[i] = valores[l];
        return;
    }
    int e = 2 * i;
    int d = 2 * i + 1;
    int m = (l + r)/2;

    build (e, l, m);
    build (d, m+1, r);

    // Junta a informação dos dois filhos
    t[i] = t[e] + t[d];
}

int query (int i, int l, int r, int ql, int qr){
    // Se o intervalo atual estiver completamente contido no intervalo que eu quero 
    if (ql <= l && r <= qr) return t[i];
    // Se o intervalo atual estiver completamente fora do intervalo que eu quero 
    if (qr < l || r < ql) return 0;
    // Quando o intervalo atual não estiver parcialmente dentro do intervalo que eu quero 
    int e = 2 * i;
    int d = 2 * i + 1;
    int m = (l + r)/2; // Metade da informção do nó

    return query(e, l, m, ql, qr) + query(d, m+1, r, ql, qr);
}

void update (int i, int l, int r, int p, int x) {
    if (l == r) t[i] = x;
    else {
        int m = (l+r)/2;
        if (p <= m) update (2*i, l, m, p, x);
        else update (2*i+1, m+1, r, p, x);
        t[i] = t[2*i] + t[2*i+1];
    }
}

int main(int argc, char) {

    return 0;
}