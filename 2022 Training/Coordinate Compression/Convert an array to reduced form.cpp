#include <bits/stdc++.h>
#define MAXN 10050
using namespace std;

void convert(int arr[], int n) {
    int temp[n];

    memcpy(temp, arr, n * sizeof(int));

    sort(temp, temp + n);

    unordered_map<int,int> umap;

    int val = 0;
    for (int i = 0; i < n; i++) {
        umap[temp[i]] = val;
        val++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = umap[arr[i]];
    }
}

int main () {
    int n;
    int arr[MAXN];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    convert(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}