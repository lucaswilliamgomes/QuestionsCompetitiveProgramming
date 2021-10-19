#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int arr[MAXN];
int n, k;


int binary_search(int value, int l, int r) {
    int m = (l + r) / 2;

    if (l + 1 >= r) return l;

    if (arr[m] <= value) {
        return binary_search(value, m, r);
    } else {
        return binary_search(value, l, m);
    }
}

int main () {

    cin >> n >> k;
    arr[0] = -INT_MAX;
    arr[n+1] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int query;
    for(int i = 0; i < k; i++) {
        cin >> query;
        cout << binary_search(query, 0, n+1) << endl;
    }


    return 0;
}