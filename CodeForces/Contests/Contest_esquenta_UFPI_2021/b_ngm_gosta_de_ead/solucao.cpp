#include <bits/stdc++.h>
#define MAXN 1000010

using namespace std;

int groups;
int pai[MAXN];

find(int x)
{
    if (pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u != v)
    {
        groups--;
        pai[u] = v;
    }
}

int main(int argc, char const *argv[])
{
    int N, Q, op;
    cin >> N >> Q;
    groups = N;

    for (int i = 1; i <= N; i++)
    {
        pai[i] = i;
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            join(a, b);
        }
        else
        {
            cout << groups << endl;
        }
    }
    return 0;
}
