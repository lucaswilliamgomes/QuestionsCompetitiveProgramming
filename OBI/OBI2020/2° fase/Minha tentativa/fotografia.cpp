#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int l, a, n;
    vector<pair<int, int>> molduras;
    float sobraMinima = 1000000;
    int ans = -1;

    cin >> l >> a >> n;
    for (int i = 0; i < n; i++)
    {
        int auxl, auxa;
        cin >> auxl >> auxa;
        molduras.emplace_back(auxl, auxa);
    }

    int cont = 1;
    for (pair<int, int> it : molduras)
    {
        float molde_l = it.first, molde_a = it.second;
        float areaSobra;
        if ((l <= molde_l && a <= molde_a) || (a <= molde_l && l <= molde_a))
        {
            areaSobra = (molde_l * molde_a) - (l * a);
            if (areaSobra < sobraMinima)
            {
                sobraMinima = areaSobra;
                ans = cont;
            }
        }
        cont++;
    }

    cout << ans << endl;

    return 0;
}
