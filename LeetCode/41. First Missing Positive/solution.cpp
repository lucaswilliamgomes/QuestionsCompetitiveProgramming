#include <bits/stdc++.h>

using namespace std;


// // O(n) time e O(n) space
// int firstMissingPositive(vector<int>& nums) {
//     unordered_map<int, int> freq;

//     for (auto it: nums) {
//         freq[it]++;
//     }

//     for (int i = 1; i <= nums.size() + 1; i++) {
//         // cout << freq[i] << " " << i << endl;
//         if (!freq[i]) return i;
//     }
// }

// O(n) time, o(i) space
int firstMissingPositive(vector<int>&  nums) {
    int i=0;
    while(i<nums.size()){
        int correct=nums[i]-1;
        //check if its positive,in range and not in correct position
        if(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[correct]){
            int temp=nums[i];
            nums[i]=nums[correct];
            nums[correct]=temp;
        }else{
            i++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;


    for(int index=0;index<nums.size();index++){
        if(nums[index]!=index+1){
            return index+1;
        }
    }
    return nums.size()+1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << firstMissingPositive(nums) << endl;

    return 0;
}
