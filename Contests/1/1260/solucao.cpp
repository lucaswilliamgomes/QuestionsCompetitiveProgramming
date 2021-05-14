#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int existe (vector<pair<string,double>> k, string v) {
    for (int i = 0; i < k.size(); i++) {
        if (v == k[i].first) return i;
    }
    return -1;
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    string lb;
    getline(cin, lb);
    getline(cin, lb);
    for (int i = 0; i < n; i++) {
        vector<pair<string,double>> trees;
        double tam = 0;
        while (true) {
            string aux;
            getline (cin, aux);
            if (aux == "" or EOF) break;
            tam++;
            int pos = existe(trees, aux);
            if (pos >= 0) {
                trees[pos].second++;
            } else {
                trees.emplace_back(aux, 1);
            }
        }
        sort(ALL(trees));
        cout << fixed << setprecision(4);
        for (int j = 0; j < trees.size(); j++) {
            cout << trees[j].first << " " << trees[j].second/tam * 100 << endl;
        } 
        cout << endl;
    }
    return 0;
}
