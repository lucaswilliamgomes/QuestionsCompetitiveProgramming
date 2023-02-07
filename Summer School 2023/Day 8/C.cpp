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
#define int long long

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

vector<int> ans;

void lps_func(string txt, vector<int> &Lps)
{
    Lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < txt.length())
    {
        if (txt[i] == txt[len])
        {
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else
        {
            if (len == 0)
            {
                Lps[i] = 0;
                i++;
                continue;
            }
            else
            {
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

void KMP(string pattern, string text)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> Lps(m);

    lps_func(pattern, Lps); // This function constructs the Lps array.

    int i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        } // If there is a match continue.
        if (j == m)
        {
            ans.push_back(i - m);
            j = Lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {               // If there is a mismatch
            if (j == 0) // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1]; //Update j as Lps of last matched character
        }
    }
}


int32_t main(int argc, char **argv)
{
    optimize;

    string a;

    // int t;
    // cin >> t;

    // while (t--) {
        ans.clear();
        string text, pat;
        getline(cin, text);
        getline(cin, pat);

        KMP(pat, text);

        if (ans.size() == 0 || text.size() == 0) {
            cout << text.size() << endl;
            return 0;
        }

        cout << ans.size() << endl;

        cout << text.size() - (ans.size() * pat.size()) << endl; 


        
    // }
    

    return 0;
}
