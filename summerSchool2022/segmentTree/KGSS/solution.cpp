// I dont know
#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int N, ar[MAXN];
pair<int,int> seg[4 * MAXN];

pair<int, int> join(pair<int, int> noL, pair<int, int> noR) {
    return max(noL, noR);
}

void build(int pos, int start, int end) {
    if (start == end) {
        seg[pos] = {ar[start], start};
        return;
    }
    
    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    build(l, start, m);
    build(r, m+1, end);

    seg[pos] = join(seg[l], seg[r]);
}

void update(int pos, int start, int end, int idx, int value) {
    if (idx < start || idx > end) return;
    if (start == end) {
        seg[pos].first = value;
        seg[pos].second = start;
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    update(l, start, m, idx, value);
    update(r, m + 1, end, idx, value);
    seg[pos] = join(seg[l], seg[r]);
}

pair<int, int> query(int pos, int start, int end, int p, int q){
    if (p > end || q < start) return {INT_MIN, 1};
    if (p <= start && end <= q) return seg[pos];

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    return join(query(l, start, m, p, q), query(r, m + 1, end, p, q));
}

int main () {
    int m;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ar[i];
    }
    build(1, 1, N);
    cin >> m;
    while(m--) {
        string op;
        int l, r;
        cin >> op >> l >> r;
        if (op == "Q") {
            pair<int, int> bigger = query(1, 1, N, l, r);
            pair<int, int> secondBigger = max(query(1, 1, N, l, a.second - 1), query(1, 1, N, a.second + 1, r));
            cout << bigger.first + secondBigger.first << endl;
        } else {
            update(1, 1, N, l, r);
        }
    }
}