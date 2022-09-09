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


int main(int argc, char** argv)
{
    optimize;
    int t1, f1, s1, p1, ps1;
    int t2, f2, s2, p2, ps2;

    cin >> t1 >> f1 >> s1 >> p1 >> ps1;
    cin >> t2 >> f2 >> s2 >> p2 >> ps2;

    int total1, total2;
    
    total1 = (t1 * 6) + (f1 * 3) + (s1 * 2) + (p1 * 1) + (ps1 * 2);
    total2 = (t2 * 6) + (f2 * 3) + (s2 * 2) + (p2 * 1) + (ps2 * 2);

    cout << total1 << " " << total2 << endl;
    
    return 0;
}