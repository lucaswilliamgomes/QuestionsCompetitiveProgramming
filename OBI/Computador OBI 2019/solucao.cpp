// solucao apenas 20 pontos
#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long 

using namespace std;

ll mem[MAXN], N, M;

void frente(int i, int v)
{
    while (v > 0 && i <= N)
    {
        mem[i] += v;
        i++;
        v--;
    }
}

void tras(int i, int v)
{
    while (v > 0 && i >= 1)
    {   
        mem[i] += v;
        i--;
        v--;
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    while (M--)
    {
        int op, i, v;
        cin >> op;
        if (op == 1)
        {
            cin >> i >> v;
            frente(i, v);
        }
        else if (op == 2)
        {
            cin >> i >> v;
            tras(i, v);
        }
        else
        {
            cin >> i;
            cout << mem[i] << endl;
        }
    }
    return 0;
}
