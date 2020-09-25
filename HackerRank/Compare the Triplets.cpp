#include <bits/stdc++.h>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int a_points = 0, b_points =0;

    for (int i = 0; i < 3; i++){
        if (a[i] > b[i]) a_points++;
        if (b[i] > a[i]) b_points++;
    }

    vector <int> points;
    points.push_back(a_points);
    points.push_back(b_points);
    return points;
}


int main () {


    return 0;
}