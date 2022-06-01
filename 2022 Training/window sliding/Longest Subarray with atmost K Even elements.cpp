#include <bits/stdc++.h>

using namespace std;

int findLongestSubArray (int arr[], int n, int k) {
    int sum_maximum = INT_MIN;
    int sum_current = 0;
    int aux = 0;
    int q = 0;
    // first 
    for (int i = 0; i < n; i+=2) {
        sum_current += arr[i];
        aux++;
        if (aux == k) {
            q = i;
            break;
        }  
    }

    sum_maximum = sum_current;

    // others
    for (int i = 2, q = q + 2; q < n; q+=2) {
        sum_current = sum_current - (arr[i - 2]) + (arr[q]);

        sum_maximum = max(sum_maximum, sum_current);

        i+=2;
    }
    
    return sum_maximum;
}


int main () {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << findLongestSubArray(arr, n, k) << endl;
    }
    return 0;
}