#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int second = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;
    // cout << first << " " << second << endl;
    if (nums[first] == target && nums[second] == target) {
        return {first, second};
    } else {
        return {-1, -1};
    }
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

    vector<int> ans = searchRange(nums, target);

    for (auto it : ans) {
        cout << it << endl;
    }
  
    return 0;
}

