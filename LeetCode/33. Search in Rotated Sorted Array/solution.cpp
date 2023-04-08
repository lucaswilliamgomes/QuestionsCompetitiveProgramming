#include <bits/stdc++.h>

using namespace std;

int findPivotIndex(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// O(log(n)) time, O(1) space
int search(vector<int>& nums, int target) {
    int ans = -1;
    int pivot = findPivotIndex(nums);

    int l = 0, r = pivot - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) return m;
        if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    l = pivot;
    r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) return m;
        if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    cout << search(nums, target) << endl;
  
    return 0;
}

