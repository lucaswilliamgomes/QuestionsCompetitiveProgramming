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

bool isPalindrome(string s) {
    string k;
    for(int i = 0; i < s.size(); i++) {
        if (toupper(s[i]) >= 65 && toupper(s[i]) <= 90 || s[i] >= 48 && s[i] <= 57) 
            k.push_back(toupper(s[i]));
    }
    for (int l = 0, r = k.size() - 1; l < (k.size() / 2); l++, r--) {
        if (k[l] != k[r]) return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    optimize;
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << endl;
    
    return 0;
}