#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int ans = -INFINITY;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (i <= 3 and j <= 3){
                ans = max (ans, (arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]));
            }
        }
    }
    return ans;
}


int main (){


    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    cout << hourglassSum(arr) << endl;

    return 0;
}