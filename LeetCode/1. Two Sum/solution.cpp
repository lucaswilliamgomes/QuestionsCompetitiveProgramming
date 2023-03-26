#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int, int> diff;
    for (int i = 0; i < nums.size(); i++) {
        diff[target-nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (diff[nums[i]] && i != diff[nums[i]]) return {i, diff[nums[i]]};
    }

    return {};
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
    
    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
