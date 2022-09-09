#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
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

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


bool isPalindrome(string str) {
    for (int l = 0, r = str.size() - 1; l < (str.size() / 2); l++) {
        if (str[l] != str[r]) return false;
        r--;
    }

    return true;
}

string toMorse(string a) {
    string ans = "";
    
    for (auto c : a) {
        if (c == 'A') 
            ans += "pt";
        else if (c == 'B') 
            ans += "tppp";
        else if (c == 'C') 
            ans += "tptp"; 
        else if (c == 'D') 
            ans += "tpp";
        else if (c == 'E') 
            ans += "p";
        else if (c == 'F') 
            ans += "pptp";
        else if (c == 'G') 
            ans += "ttp";
        else if (c == 'H') 
            ans += "pppp";
        else if (c == 'I') 
            ans += "pp";
        else if (c == 'J') 
            ans += "pttt";                        
        else if (c == 'K') 
            ans += "tpt";
        else if (c == 'L') 
            ans += "ptpp";
        else if (c == 'M') 
            ans += "tt";
        else if (c == 'N') 
            ans += "tp";
        else if (c == 'O') 
            ans += "ttt";
        else if (c == 'P') 
            ans += "pttp";
        else if (c == 'Q') 
            ans += "ttpt";
        else if (c == 'R') 
            ans += "ptp";
        else if (c == 'S') 
            ans += "ppp";
        else if (c == 'T') 
            ans += "t";
        else if (c == 'U') 
            ans += "ppt";
        else if (c == 'V') 
            ans += "pppt";
        else if (c == 'W') 
            ans += "ptt";
        else if (c == 'X') 
            ans += "tppt";
        else if (c == 'Y') 
            ans += "tptt";
        else if (c == 'Z') 
            ans += "ttpp";
        else if (c == '0') 
            ans += "ttttt";
        else if (c == '1') 
            ans += "ptttt";
        else if (c == '2') 
            ans += "ppttt";
        else if (c == '3') 
            ans += "ppptt";
        else if (c == '4') 
            ans += "ppppt";
        else if (c == '5') 
            ans += "ppppp";
        else if (c == '6') 
            ans += "tpppp";
        else if (c == '7') 
            ans += "ttppp";
        else if (c == '8') 
            ans += "tttpp";
        else if (c == '9') 
            ans += "ttttp";
    }
    if (!ans.size()) return "as";
    return ans;
}

void solve(string a) {
    string aa = "";

    for (auto it : a) {
        aa += toupper(it);
    }

    aa = toMorse(aa);

    if (isPalindrome(aa)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(int argc, char** argv)
{
    optimize;
    string a;
    getline(cin, a);
    solve(a);
    return 0;
}