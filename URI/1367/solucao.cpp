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
    int n;

    while (scanf("%d", &n)) {
        if(n == 0) break;
        char indent, aux = 'A';
        int time, contCorrect = 0, contIncorrect = 0, timeTotal = 0;
        string correcao;  
        while (n--)
        {
            cin >> indent >> time >> correcao;
            if (indent == aux) {
                if (correcao == "correct") {
                    contCorrect++;
                    timeTotal += (contIncorrect * 20) + time;
                } else {
                    contIncorrect++;
                }
            } else {
                contIncorrect = 0;
                aux = indent;
                if (correcao == "correct") {
                    contCorrect++;
                    timeTotal += time;
                } else {
                    contIncorrect++;
                }

            }
        }
        
        cout << contCorrect << " " << timeTotal << endl;
    }
    return 0;
}
