#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double ans;
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());

    if (nums1.size() % 2 == 0) {
        ans = (double)(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
    } else {
        ans = nums1[nums1.size() / 2];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> array1(n), array2(m);

    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> array2[i];
    }

    cout << findMedianSortedArrays(array1, array2) << endl;
    return 0;
}
