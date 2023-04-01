#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> notRepeateds;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        int l = i + 1, r = nums.size() - 1;

        while (l < r) {
            if (nums[i] + nums[l] + nums[r] < 0) l++;
            else if (nums[i] + nums[l] + nums[r] > 0) r--;
            else {
                notRepeateds.insert({nums[i], nums[l], nums[r]});
                l++;
                r--;
            }
        }
    }

    for (auto element: notRepeateds) {
        ans.push_back(element);
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

    vector<vector<int>> ans = threeSum(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }

    return 0;
}
