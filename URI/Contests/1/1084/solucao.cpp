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
    
    while (true) {
        string d, q, num;

        vector<char> aux;
        cin >> d >> q;
        if (d == "0" and q == "0") break;
        cin >> num;
        for (int i = 0; i < num.length(); i++) {
            aux.push_back(num[i]);
        }
        sort(ALL(aux));
        for (; aux.size() != stoi(q) ; ) {
            aux.pop_back();
        }
        for (int i = 0; i < num.length(); i++){
            if (find (aux.begin(), aux.end(), num[i]) != aux.end()) continue;
            cout << num[i];
        }
        cout << endl;
    }
    return 0;
}
