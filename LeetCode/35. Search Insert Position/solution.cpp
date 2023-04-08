#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
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

    cout << searchInsert(nums, target) << endl;
  
    return 0;
}

