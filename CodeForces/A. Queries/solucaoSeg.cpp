#include <bits/stdc++.h>
#define ll long long 
#define MAXN 2000020
using namespace std;

ll t[10][4 * MAXN], ar[MAXN], N, M;

void build(int i, int l, int r, int mod){
    if (l == r){
        t[mod][i] = ar[l]%M;
        return;
    }

    int e = 2*i;
    int d = 2*i+1;
    int m = (l+r)/2;

    build(e, l, m);
    build(d, m+1, r);

    t[i] = t[e] + t[d];
}

ll query(int i, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[i];
    if (l > qr || r < qr) return 0;
    
    int e = 2 * i;
    int d = 2 * i + 1;
    int m = (l+r) / 2;

    return query(e, l, m, ql, qr) + query(d, m+1, r, ql, qr);
}

void update (int i, int l, int r, int p, ll v) {
    if (l == r) t[i] = v;
    else {
        int m = (l+r)/2;
        int e = 2*i;
        int d = 2*i+1;
        if (p <= m) update(e, l, m, p, v);
        else update(d, m+1, r, p, v); 
        t[i] = t[e] + t[d];
    }
}

int main () {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> ar[i];
    }

    build(1, 1, N);

    int q, l, r, mod;
    char op;
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 's') {

        } else {
            if ()
        }

    }

    return 0;
}


t