#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m, aux;
    cin >> n >> m;
    vector <int> arr;
    for (int i = 0; i < 1005; i++){
        arr.push_back(0);
    }
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort (arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    int ans = m;
    int atual = arr[ans-1];
    int proximo = arr[ans];
    

    while (proximo == atual){
        ans++;
        atual = arr[ans-1];
        proximo = arr[ans];
    }

    cout << ans << endl;
    return 0;
}