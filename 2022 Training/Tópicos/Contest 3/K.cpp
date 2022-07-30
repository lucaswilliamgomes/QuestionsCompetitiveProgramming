#include <bits/stdc++.h>

using namespace std;

vector<int> ar;
int n;

bool problem(int el, int index) {
    for (int i = index; i < n; i++) {
        if (ar[i] > el) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    ar.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i++) {
        if (problem(ar[i], i + 1)) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
   

    return 0;
}
