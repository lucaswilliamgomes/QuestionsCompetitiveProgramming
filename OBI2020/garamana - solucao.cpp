// TEMPORARIA

#include <bits/stdc++.h>
using namespace std;

map <char, int> freqP, freqA;

int main () {
    string palavra, anagrama;

    cin >> palavra >> anagrama;
    int tam = palavra.size();

    for (char it : palavra){
        freqP[it]++;
    }

    for (char it : anagrama){
        freqA[it]++;
    }

    for (char x = 'a'; x <= 'z'; x++){
        if (freqA[x] > freqP[x]){
            cout << 'N' << endl;
            return 0;
        }
    }

    cout << 'S' << endl;
    return 0;
}