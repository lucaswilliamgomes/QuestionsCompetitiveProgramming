#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {

    int tam = arr.size();
    int difference = 0;
    
    for (int i = 0; i < tam; i++){
        difference += arr[i][i]; 
    }

    for (int i = 0; i < tam; i++){
        difference -= arr[tam-i-1][i]; 
    }

    return abs(difference);
}

int main () {

    return 0;
}