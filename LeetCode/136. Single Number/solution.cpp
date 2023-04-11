#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1, k = 0; i < nums.size(); i++) {  
        if (nums[i] != nums[i-1]) {
            if (k == 0) {
                return nums[i-1];
            } else k = 0;
        } else k++;
    }

    return nums[nums.size()-1];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = threeSum(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }

    return 0;
}
