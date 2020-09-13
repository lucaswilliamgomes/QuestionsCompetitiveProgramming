#include <bits/stdc++.h>

using namespace std;

int main () {
    int B, T, areatotal, base = 160, altura = 70;
    double areadireita, areaesquerda;
    areatotal = base * altura;
    cin >> B >> T;
    areaesquerda = ((B+T) * altura) / 2;
    areadireita = areatotal - areaesquerda;

    if(areaesquerda > areadireita) cout << 1;
    else if (areaesquerda < areadireita) cout << 2;
    else cout << 0;

    return 0;
}