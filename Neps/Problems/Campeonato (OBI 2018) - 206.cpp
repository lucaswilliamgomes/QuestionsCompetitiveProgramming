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
    int aux;
    float a, b;
    vector <int> ordem;

    for (int i = 1; i <= 16; i++) {
        cin >> aux;
        ordem.push_back (aux);
    }

    for (int i = 0; i < 16; i++) {
        if (ordem[i] == 1) a = i+1;
        if (ordem[i] == 9) b = i+1;
    }

    if (ceil(a/2) == ceil(b/2)) cout << "oitavas" << endl;
    else if (ceil(a/4) == ceil(b/4)) cout << "quartas" << endl;
    else if (ceil(a/8) == ceil(b/8)) cout << "semifinal" << endl;
    else cout << "final" << endl; 
  
    return 0;
}