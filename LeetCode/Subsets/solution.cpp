#include <bits/stdc++.h>

using namespace std;

bool equals (vector<int>& element1, vector<int>& element2) {
    if (element1.size() != element2.size()) return false;
    for (int i = 0; i < element1.size(); i++) {
        if (element1[i] != element2[i]) return false;
    }
    return true;
}

bool verifyDuplicateds (vector<vector<int>>& res,vector<int>& element) {
    for (auto it : res) {
        if (equals(it, element)) return true;
    }
    return false;
}

void subsetsUtil(vector<int>& A,vector<vector<int>>& res,vector<int>& subset, int index) {
    if (!verifyDuplicateds(res, subset)) {
        res.push_back(subset);
    }
    for(int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        subsetsUtil(A,res, subset, i+1);
        subset.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> subset;
    subsetsUtil(nums,res, subset, 0);
    return res;
}

int main() {
    vector<int> test = {4,4,4,1,4};

    vector<vector<int>> res = subsets(test);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}