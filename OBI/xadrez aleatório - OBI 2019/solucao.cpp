#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n >> t;
    if (t == 0)
    {
        cout << n << endl;
    }
    else if (t == 1)
    {
        cout << n * (n - 1) << endl;
    }
    else
    {
        int ans = 0, j = n - 2, cont = 1;
        while (j > n / 2)
        {
            ans += j * cont;
            cont++;
            j--;
        }
        if (n % 2 == 0)
        {
            cout << (ans * 2) + (n / 2 * cont * 2) << endl;
        }
        else
        {
            cout << (ans * 2) + (n / 2 * cont) << endl;
        }
    }

    return 0;
}
