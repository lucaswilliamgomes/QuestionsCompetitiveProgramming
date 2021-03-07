#include <bits/stdc++.h>

using namespace std;

int main () {
    int A[1000000];
    int N, key, in;
    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    for (int j = 2; j <= N; j++){
        key = A[j];
        in = j - 1;
        while (in > 0 and A[in] > key) {
            A[in+1] = A[in];
            in=in-1;
        }
        A[in + 1] = key;
    }

    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    
    cout << endl;
    return 0;
}
