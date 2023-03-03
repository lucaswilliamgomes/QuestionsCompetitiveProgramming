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
#define MAXN 201010
#define MAXL 23
#define endl '\n'
#define int ll

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

bool solve(map<char, int> strs, map<char, int> strt, char biggestInS, char biggestInT) {
    if (biggestInT != 'a') return true;
    else {
        if (biggestInS != 'a') return false;
        else return strs['a'] < strt['a'];
    }
}

int32_t main(int argc, char **argv)
{
    optimize;
    int t;
    cin >> t;
    while (t--) {
        map<char,int> strs, strt;
        char biggestInS = 'a', biggestInT = 'a';
        strs['a']++; strt['a']++;
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int op, k;
            string text;
            cin >> op >> k >> text;

            if (op == 1) {
                for (int i = 0; i < text.size(); i++) {
                    if (text[i] > biggestInS) biggestInS = text[i];
                    strs[text[i]]+=k;
                }
            } else {
                for (int i = 0; i < text.size(); i++) {
                    if (text[i] > biggestInT) biggestInT = text[i];
                    strt[text[i]]+=k;   
                }
            }

            if (solve(strs, strt, biggestInS, biggestInT)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    
    return 0;
}