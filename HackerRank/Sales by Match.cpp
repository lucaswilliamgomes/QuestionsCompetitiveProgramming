#include <bits/stdc++.h>

using namespace std;

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    int ans = 0;
    sort(ar.begin(), ar.end());
    for (int i = 1; i < ar.size(); ){
        if (ar[i] == ar[i-1]){
            ans++;
            i+=2;
        } else i++;
    }
    return ans;
}

int main()
{
    int n, aux;
    cin >> n;

    vector<int> ar;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        ar.push_back(aux);
    }

    int result = sockMerchant(n, ar);

    cout << result << endl;

    return 0;
}

