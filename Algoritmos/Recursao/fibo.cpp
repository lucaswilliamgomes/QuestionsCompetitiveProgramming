#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fibo[100010];

// Recursivo

ll fibonacciRecursivo(ll num)
{
    if (fibo[num])
        return fibo[num];
    else
    {
        if (num == 0)
            return fibo[0] = 0;
        else if (num == 1 || num == 2)
            return fibo[1] = fibo[2] = 1;
        else
        {
            fibo[num - 1] = fibonacciRecursivo(num - 1);
            fibo[num - 2] = fibonacciRecursivo(num - 2);
            return (fibo[num - 1] + fibo[num - 2]);
        }
    }
}

// Iterativo
ll fibonacciIterativo(ll num)
{

    for (int i = 1; i <= num; i++)
    {
        if (i == 1 || i == 2)
            fibo[i] = 1;
        else
        {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
    }
    return fibo[num];
}

int main()
{
    ll num;
    cin >> num;
    cout << fibonacciIterativo(num) << endl;
    return 0;
}