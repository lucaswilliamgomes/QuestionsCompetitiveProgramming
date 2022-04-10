#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int a[MAXN], updates[MAXN], diff[MAXN];

void update(int a[], int n, int updates[], int k)
{
    for (int i = 0; i < k; i++) {
        diff[updates[i] - 1]++;
    }

    a[0] = diff[0];    
    for (int i = 1; i < n; i++) {
        a[i] = a[i-1] + diff[i];
    }
}

int main () {
    int n, k, aux;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> updates[i];
    }

    update(a, n, updates, k);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}