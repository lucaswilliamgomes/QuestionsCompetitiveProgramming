#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int arr[MAXN];

int binary_search(int value, int l, int r) {
    int m = (l + r) / 2;

    if (arr[m] == value) return m;
    
    if (l >= r) return -1;
    else {
        if (arr[m] > value) {
            binary_search(value, l, m);
        } else {
            binary_search(value, m+1, r);
        }
    }
}

int main () {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int query;
    for (int i = 0; i < k; i++) {
        cin >> query;
        if (binary_search(query, 1, n) != -1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}