#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int main(int argc, char const *argv[]){

    vector<pair<int, int>> db;
    vector<int> respondidos;

    int N, aux;
    char a;

    cin >> N;

    while (N--) {
        cin >> a >> aux;

        if (a == 'R') {
            bool existe = false;
            for (auto it : db) {
                if (it.first == aux) {
                    it.second++;
                    existe = true;
                    break;
                }
            }
            if (existe == false) {
                db.emplace_back(aux, 0);
            }
            
        }






    }



    
    return 0;
}
