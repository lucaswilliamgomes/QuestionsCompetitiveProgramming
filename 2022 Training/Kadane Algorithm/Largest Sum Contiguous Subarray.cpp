#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum (int a[], int n) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here += a[i];
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

int main () {
    int a[] = {-2, -3, -1, -1, -2, -2, -1, -3};
    int n = sizeof(a)/sizeof(a[0]);

    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;

    return 0;
}