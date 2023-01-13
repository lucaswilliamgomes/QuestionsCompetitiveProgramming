#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
#define EPS 1e-6
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    arr[0] = 1;

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        int k = 1;
        if (n == 1) {
            cout << 1 << endl;
            break;
        }
        for (int i = 0; i < 500; i++) {
            k += i + 1;
            if(k >= n) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}