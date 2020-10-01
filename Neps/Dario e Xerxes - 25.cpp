#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;



bool verifica (vector <int> ganho, int num) {
    for (int i = 0; i < 2; i++){
        if(num == ganho[i]) return true;
    }
    return false;
}

int main(){
    int n, jogada1, jogada2, dario = 0, xerxes = 0;
    cin >> n;

    //vector < pair <int, int> > jogadas;

    vector <int> regras[10];

    regras[0].push_back(1);
    regras[0].push_back(2);

    regras[1].push_back(2);
    regras[1].push_back(3);

    regras[2].push_back(3);
    regras[2].push_back(4);

    regras[3].push_back(4);
    regras[3].push_back(0);

    regras[4].push_back(0);
    regras[4].push_back(1);

    //cout << regras[0][0] << " " << regras[0][1];


    for (int i = 0; i < n; i++){
        cin >> jogada1 >> jogada2;
        if (verifica (regras[jogada1], jogada2))dario++;
        else xerxes++;
    }

    if (dario > xerxes) cout << "dario" << endl;
    else cout << "xerxes" << endl;

    return 0;
}
