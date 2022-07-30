#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int n, t;
    map<pair<int, int>, string> code;
    cin >> n;

    while(n--) {
        int aux_a, aux_b;
        pair<int, int> aux_p;
        string name;
        cin >> aux_a >> aux_b >> name;
        aux_p.first = aux_a;
        aux_p.second = aux_b;
        
        code[aux_p] = name;
    }

    // for (auto it: code) {
    //     cout << it.first.first << " " << it.first.second << " - " << it.second << endl; 
    // }
    cin >> t;

    while (t--) {
        int aux_a, aux_b;
        pair<int, int> aux_p;
        cin >> aux_a >> aux_b;
        aux_p.first = aux_a;
        aux_p.second = aux_b;
        cout << code[aux_p] << endl;
    }
   

    return 0;
}
