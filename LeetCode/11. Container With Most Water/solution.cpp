#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int maxA = 0, l = 0, r = height.size() - 1;

    while(l < r) {
        maxA = max(maxA, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r]) l++;
        else r--;
    }

    return maxA;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << maxArea(heights) << endl;
}
