#include <bits/stdc++.h>
#define MAX 550

using namespace std;

int M[MAX][MAX], N, F;

void flood_fill(int x, int y, int f)
{
    if (M[x][y] == -1)
        return;

    if (M[x][y] <= f)
    {
        M[x][y] = -1;
    }
    else
    {
        return;
    }

    if (x + 1 < N)
    {
        flood_fill(x + 1, y, f);
    }
    if (x - 1 >= 0)
    {
        flood_fill(x - 1, y, f);
    }
    if (y + 1 < N)
    {
        flood_fill(x, y + 1, f);
    }
    if (y - 1 >= 0)
    {
        flood_fill(x, y - 1, f);
    }
}

int main(int argc, char const *argv[])
{
    string linha;

    cin >> N >> F;

    for (int i = 0; i < N; i++)
    {
        cin >> linha;
        for (int j = 0; j < N; j++)
        {
            M[i][j] = linha[j] - '0';
        }
    }

    flood_fill(0, 0, F);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (M[i][j] == -1)
            {
                cout << '*';
            }
            else
            {
                cout << M[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
