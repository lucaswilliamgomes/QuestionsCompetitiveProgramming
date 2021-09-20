#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, aux, atual = 0, max = 0;

    cin >> n;
    while (n--) {
        cin >> aux;
        atual += aux;

        if (max < atual) max = atual;

        if (atual < 0) atual = 0;
    }
    cout << max << endl;
    return 0;
}
