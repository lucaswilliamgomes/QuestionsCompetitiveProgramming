#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    double value = INFINITY;
    double p, g;
    while (n--)
    {
        cin >> p >> g;
        if (((p / g) * 1000) < value)
            value = (p / g) * 1000;
    }

    printf("%.2lf\n", value);

    return 0;
}
