#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int numbers[1005];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    int ans = 1;
    for (int i = 2; i < n; i++){
        if((numbers[i] - numbers[i-1]) != (numbers[i-1] - numbers[i-2])) ans++;
    }

    cout << ans << endl; 
    return 0;
}



