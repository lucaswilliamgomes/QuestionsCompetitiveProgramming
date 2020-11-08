#include <bits/stdc++.h>

using namespace std;

int main () {
    int alunos, maximo, ans = 0;
    cin >> maximo >> alunos;

    while (alunos){
        if (alunos > maximo-1){
            alunos -= maximo-1;
            ans++;
        } else{
            alunos = 0;
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}