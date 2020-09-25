#include <bits/stdc++.h>

using namespace std;


void plusMinus(vector<int> arr) {
    int tam = arr.size();
    double bigger = 0;
    double zero = 0;
    double smaller = 0;
    double ans;

    for (int i = 0; i < tam; i++){
        if (arr[i] == 0) zero++;
        else if (arr[i] < 0) smaller++;
        else bigger++;
    }
    ans = bigger/tam;
    printf ("%.6lf\n", ans);
    ans = smaller/tam;
    printf ("%.6lf\n", ans);
    ans = zero/tam;
    printf ("%.6lf\n", ans);

}

int main () {

    vector <int> arr;
    int n, aux;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> aux;
        arr.push_back(aux);
    }

    plusMinus(arr);

    return 0;
}