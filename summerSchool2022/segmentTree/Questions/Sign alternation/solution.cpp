#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int ar[MAXN], N, M;
pair<int, int> seg[4 * MAXN];

pair<int, int> join(pair<int, int> noL, pair<int, int> noR)
{
    return pair<int, int>(noL.first + noR.first, noL.second + noR.second);
}

void build(int pos, int start, int end)
{
    if (start == end)
    {
        if (start % 2 == 0)
            seg[pos] = {ar[start], 0};
        else
            seg[pos] = {0, ar[start]};
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    build(l, start, m);
    build(r, m + 1, end);

    seg[pos] = join(seg[l], seg[r]);
}

void update(int pos, int start, int end, int idx, int value)
{
    if (idx < start || idx > end)
        return;
    if (start == end)
    {
        if (idx % 2 == 0)
            seg[pos].first = value;
        else
            seg[pos].second = value;
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    update(l, start, m, idx, value);
    update(r, m + 1, end, idx, value);

    seg[pos] = join(seg[l], seg[r]);
}

pair<int, int> query(int pos, int start, int end, int p, int q)
{
    if (q < start || p > end)
        return {0, 0};
    if (p <= start && end <= q)
        return seg[pos];

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    return join(query(l, start, m, p, q), query(r, m + 1, end, p, q));
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> ar[i];
    }
    build(1, 1, N);
    cin >> M;
    while (M--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
        {
            update(1, 1, N, a, b);
        }
        else
        {
            pair<int, int> ans = query(1, 1, N, a, b);
            if (a % 2 == 0)
                cout << ans.first - ans.second << endl;
            else
                cout << ans.second - ans.first << endl;
        }
    }
    return 0;
}