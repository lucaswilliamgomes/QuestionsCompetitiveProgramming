#include <bits/stdc++.h>

using namespace std;

vector<int> sieveOfEratosthenes(int N)
{
    vector<int> ans;
    vector<bool> isPrime(N + 1);

    for (int i = 0; i < N + 1; i++) {
        isPrime[i] = true;
    }
    
    for (int i = 2; i*i <= N; i++) {
        for (int j = 2; j * i <= N; j++) {
            isPrime[j*i] = false;
        }
    }

    for (int i = 2; i < N+1; i++) {
        if (isPrime[i]) ans.push_back(i);
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<int> ans = sieveOfEratosthenes(N);

    for (auto it: ans) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}