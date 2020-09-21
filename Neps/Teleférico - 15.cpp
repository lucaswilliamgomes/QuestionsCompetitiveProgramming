#include <bits/stdc++.h>

using namespace std;

int main () {
    int students, capacity, ans;

    cin >> capacity >> students;

    if (students % (capacity - 1) == 0)
        ans = ( students / (capacity - 1) );
    else ans = ( students / (capacity - 1) + 1);

    cout << ans << endl;

    return 0;
}