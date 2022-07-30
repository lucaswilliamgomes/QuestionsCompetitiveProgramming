#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ar;
    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(5);


    auto it = lower_bound(ar.begin(), ar.end(), 3);

    cout << it - ar.begin() << " " << ar[it - ar.begin()] << endl;

    return 0;
}
