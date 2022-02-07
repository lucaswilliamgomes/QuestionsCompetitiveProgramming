#include <bits/stdc++.h>
#define MAXN 100005
#define ll long long
using namespace std;

int ar[MAXN];
ll seg[4 * MAXN];

void update(int pos, int start, int end, int p, int q, int value) {
    if (p > end || q < start) return;
    if (p <= start && end <= q) {
        seg[pos] += value;
        return;
    }
    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    update(l, start, m, p, q, value);
    update(r, m + 1, end, p, q, value);
    // seg[pos] = seg[l] + seg[r];
}

ll query(int pos, int start, int end, int idx) {
    ll ans = 0;
    if(start > idx || end < idx) return 0;
    if (start <= idx && end >= idx) {
        ans += seg[pos];
    }
    if (start == end && start == idx) {
        return seg[pos];
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    ans += query(l, start, m, idx);
    ans += query(r, m+1, end, idx);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 1, n, l+1, r, v);
        } else {
            int i;
            cin >> i;
            cout << query(1, 1, n, i+1) << endl;
        }
    }
}
