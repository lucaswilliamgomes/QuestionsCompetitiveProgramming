#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, num;

    vector <int> numbers;
    vector <int> notconsec;
    vector <int> ans;
 
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> num;
        numbers.push_back(num);
    }

    for (int i = 0; i < (N-1); i++){
        if (numbers[i] == numbers[i+1]) continue;   
        for (int j = 0; j < N; j++) {
            
        }
    }






    return 0;
}