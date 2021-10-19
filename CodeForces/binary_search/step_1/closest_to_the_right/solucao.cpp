#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int arr[MAXN], N, K;

int binary_search(int value, int l, int r) {

    while (r > l + 1) {
        int m = (l + r) / 2;
        if (arr[m] < value) {
            l = m;
        } else {
            r = m;
        }
    }   
    return r;
}

int main () {
    cin >> N >> K;
    arr[0] = -INT_MAX;
    arr[N+1] = INT_MAX;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int query;
    for(int i = 0; i < K; i++) {
        cin >> query;
        cout << binary_search(query, 0, N+1) << endl;
    }

    return 0;
}