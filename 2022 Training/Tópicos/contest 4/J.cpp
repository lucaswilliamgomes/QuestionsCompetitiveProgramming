#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, vector<int>> camisas;

int main () {
    int n;
    cin >> n;

    vector<int> prices(n), f_colors(n), b_colors(n);
    
    for (int i = 0; i< n; i++) {
        cin >> prices[n];
    }

    for (int i = 0; i< n; i++) {
        cin >> f_colors[n];
    }

    for (int i = 0; i< n; i++) {
        cin >> b_colors[n];
    }

    for (int i = 0; i < n; i++) {
        pair<int, int> colors(f_colors[i], b_colors[i]);
        camisas[colors].push_back(prices[i]);
    }

    for (auto it : camisas) {
        sort(it.second.begin(), it.second.end());
    }

    int buyers;
    cin >> buyers;
    vector<int> compras(buyers);

    for (int i = 0; i < buyers; i++) {
        int color;
        cin >> color;

        int b_f;

        if (camisas)

    }



    return 0;
}