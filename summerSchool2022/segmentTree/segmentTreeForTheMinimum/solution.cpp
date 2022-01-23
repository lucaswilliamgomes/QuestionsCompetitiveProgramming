#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

int N, M, ar[MAXN];
int seg[4 * MAXN];

void build(int pos, int start, int end)
{
    if (start == end)
    {
        seg[pos] = ar[start];
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    build(l, start, m);
    build(r, m + 1, end);

    seg[pos] = min(seg[l], seg[r]);
}

void update(int pos, int start, int end, int value, int idx)
{
    if (idx < start || idx > end)
        return;
    if (start == end)
    {
        seg[pos] = value;
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    update(l, start, m, value, idx);
    update(r, m + 1, end, value, idx);

    seg[pos] = min(seg[l], seg[r]);
}

int query(int pos, int start, int end, int p, int q)
{
    if (q < start || p > end)
        return INT_MAX;
    if (p <= start && end <= q)
        return seg[pos];

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    return min(query(l, start, m, p, q), query(r, m + 1, end, p, q));
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> ar[i];
    }
    build(1, 1, N);

    int op, a1, a2;
    while (M--)
    {
        cin >> op >> a1 >> a2;
        if (op == 1)
        {
            update(1, 1, N, a2, a1+1);
        }
        else
        {
            cout << query(1, 1, N, a1+1, a2) << endl;
        }
    }
}