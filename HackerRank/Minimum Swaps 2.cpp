#include <bits/stdc++.h>

using namespace std;

int minimumSwaps(vector<int> arr) {
    int tam = arr.size(), ans = 0;
    
    for (int i = 0; i < tam; i++){
        while (arr[i] != (i+1)){
            swap(arr[i], arr[arr[i] - 1]);
            ans++;
        }
    }
    return ans;
}
int main (){
    int n, aux;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> aux;
        arr.push_back(aux);
    }
    cout << minimumSwaps(arr) << endl;
    return 0;
}


//1 2 3 4 5 6 7  1 3 2 4 5 6 7  1 3 5   2  
//1 3 5 2 4 6 7  1 3 5 2 4 6 7  1 3 5 2 4 6 7 
