#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

int N, M, ar[MAXN];
pair<int, int> seg[4 * MAXN];

pair<int,int> join (pair<int,int> noL, pair<int,int> noR) {
    if (noL.first == noR.first)
        return pair<int,int> (noL.first, noL.second + noR.second);
    return min(noL, noR);
}

void build(int pos, int start, int end)
{
    if (start == end)
    {
        seg[pos].first = ar[start];
        seg[pos].second = 1;
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;
    build(l, start, m);
    build(r, m + 1, end);

    seg[pos] = join(seg[l], seg[r]);
}

void update(int pos, int start, int end, int value, int idx)
{
    if (idx < start || idx > end)
        return;
    if (start == end)
    {
        seg[pos].first = value;
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    update(l, start, m, value, idx);
    update(r, m + 1, end, value, idx);

    seg[pos] = join(seg[l], seg[r]);
}

pair<int,int> query(int pos, int start, int end, int p, int q)
{
    if (q < start || p > end)
        return {INT_MAX, 1};
    if (p <= start && end <= q)
        return seg[pos];

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    return join(query(l, start, m, p, q), query(r, m + 1, end, p, q));
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> ar[i];
    }
    build(1, 1, N);

    // for (int i = 0; i < 15; i++) {
    //     cout << seg[i].first << " " << seg[i].second << endl;
    // }

    int op, a1, a2;
    while (M--)
    {
        cin >> op >> a1 >> a2;
        if (op == 1)
        {
            update(1, 1, N, a2, a1 + 1);
        }
        else
        {
            pair<int,int> result = query(1, 1, N, a1 + 1, a2);
            cout << result.first << " " << result.second << endl;
        }
    }
}