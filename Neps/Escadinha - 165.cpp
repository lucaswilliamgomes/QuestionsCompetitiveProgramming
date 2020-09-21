#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    vector <int> numbers;
    int N;
    ll number;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> number;
        numbers.push_back(number);
    }

    if (numbers.size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    int tam = numbers.size();

    for(int i = 0; i < tam; i++){
        for(int i = 0; i < tam; i++){
        
        }
    }
    



    return 0;
}