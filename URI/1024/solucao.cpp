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
    string str;
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, str);
        int tam = str.length();
        for (int i = 0; i < tam; i++){ 
            if (isalpha(str[i])) {
                str[i] += 3;
            }
        }

        reverse(ALL(str));

        for (int i = tam/2; i < tam; i++){ 
            str[i] -= 1;
        }
        cout << str << endl;
    }

    return 0;
}
