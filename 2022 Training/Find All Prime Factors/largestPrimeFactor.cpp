#include <bits/stdc++.h>

using namespace std;

long long int largestPrimeFactor(int N)
{
    long long int ans;
    int p = 2;

    while (N > 1) {
        if (N % p == 0) {
            ans = p;
            N /= p;
        } else {
            p++;
        }
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;
    cout << largestPrimeFactor(N) << endl;
    return 0;
}