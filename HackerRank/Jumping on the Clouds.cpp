#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int ans = 0;
    for (int i = 0; i < c.size()-1; ){
        if (c[i+2] == 0) {
            ans++;
            i+=2;
        } else {
            ans++;
            i++;
        }
    }
    return ans;
}

int main()
{
    int n, aux;
    cin >> n;

    vector<int> c;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        c.push_back(aux);
    }

    int result = jumpingOnClouds(c);

    cout << result << "\n";
    return 0;
}
