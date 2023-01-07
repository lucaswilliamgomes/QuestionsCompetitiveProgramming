#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // int index1 = m - 1, index2 = 0;

    // while(index2 < n) {
    //     if (nums2[index2] > nums1[index1]) {
    //         nums1.insert(nums1.begin() + index1 + 1, nums2[index2]);
    //         index2++;
    //         index1 = m -1;
    //     }
    //     index1--;
    // }

    nums1.erase(nums1.begin() + m, nums1.end());

    for (int i = 0; i < n; i++) {
        nums1.push_back(nums2[i]);
    }

    sort(nums1.begin(), nums1.end());
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> m >> n;

    vector<int> nums1(n), nums2(m);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    
    merge(nums1, m, nums2, n);

    return 0;
}