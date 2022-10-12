#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int removeDuplicates(vector<int>& nums) {
    int k = 1, curr = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[curr]) {
            curr = i;
            k++;
        }
        else 
            nums[i] = INT32_MAX;
    }

    sort(nums.begin(), nums.end());

    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    return k;
}


int main(int argc, char **argv)
{
    optimize;
    int n;
    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(ALL(nums));

    cout << removeDuplicates(nums) << endl;

    return 0;
}
