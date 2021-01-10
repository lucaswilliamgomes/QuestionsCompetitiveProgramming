#include <bits/stdc++.h>
#define ll long long 
#define MAXN 2000020
using namespace std;

ll t[4 * MAXN], ar[MAXN], N, M;

void build(int i, int l, int r){
    if (l == r){
        t[i] = ar[l];
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
    if (l > qr || r < ql) return 0;
    
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

    for (ll i = 1; i <= N; i++){
        cin >> ar[i];
    }

    build(1, 1, N);

    // for (int i = 0; i < 20; i++){
    //     cout << t[i] << " ";
    // }
    // cout << endl;

    ll op, a, b;

    while(M--) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            update (1, 1, N, a+1, b);

        } else {
            cin >> a >> b;
            cout << query (1, 1, N, a+1, b) << endl;
        }
    }
    return 0;
}

