#include <bits/stdc++.h>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout << "ate aqui ok\n"
using namespace std;

ll n, m, tree[4 * 100010], lista[100010], lazy[4 * 100010];

pair<ll, ll> seg[4 * 100010];

void refresh(int pos, int start, int end)
{
    if (seg[pos].second == 0)
        return;

    ll num = seg[pos].second;
    seg[pos].second = 0;

    seg[pos].first += (end - start + 1) * num;

    if (start == end)
        return;

    int l = 2 * pos, r = 2 * pos + 1;
    seg[l].second += num;
    seg[r].second += num;
}

// void update(int no, int l, int r, int pos, int val)
// {

// 	if(pos < l || r < pos) return;
// 	if(l == r){ tree[no] = val; return; }

// 	int meio = (l+r)/2,
// 	esq = 2*no,
// 	dir = esq+1;

// 	update(esq, l, meio, pos, val);
// 	update(dir, meio+1, r, pos, val);

// 	tree[no] = tree[esq] + tree[dir];
// }

ll query(int pos, int start, int end, int p, int q)
{
    refresh(pos, start, end);
    if (q < start || p > end)
        return 0;
    if (p <= start && end <= q)
        return seg[pos].first;

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    return query(l, start, m, p, q) + query(r, m + 1, end, p, q);
}

void updateRange(int pos, int start, int end, int p, int q, ll val)
{
    refresh(pos, start, end);

    if (q < start || p > end)
        return;

    if (p <= start && end <= q)
    {
        seg[pos].second += val;
        refresh(pos, start, end);
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos, r = 2 * pos + 1;

    updateRange(l, start, m, p, q, val);
    updateRange(r, m + 1, end, p, q, val);
    seg[pos].first = seg[l].first + seg[r].first;
}

int main()
{
    optimize;

    int caso = 1;

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> lista[i];
            updateRange(1, 1, n, i, i, lista[i]);
        }

        cin >> m;

        cout << "Case " << caso << "#:" << endl;

        for (int i = 0, o, x, y; i < m; i++)
        {
            cin >> o >> x >> y;

            if (o == 1)
            {
                cout << query(1, 1, n, x, y) << endl;
            }
            else
            {
                for (int j = x; j <= y; j++)
                {
                    lista[j] = sqrt(lista[j]);
                    updateRange(1, 1, n, j, j, lista[j]);
                }
            }
        }

        cout << endl;
    }

    return 0;
}