#include <bits/stdc++.h>

using namespace std;

bool is_primo(int num)
{
    int raiz = sqrt(num);
    if (num == 1)
        return false;

    for (int x = 2; x <= raiz; x++)
        if (num % x == 0)
            return false;

    return true;
}

int main()
{
    int n, number;
    cin >> n;
    while (n--)
    {
        cin >> number;
    }
    return 0;
}