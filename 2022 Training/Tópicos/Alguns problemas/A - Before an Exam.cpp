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

int D, SUM;
vector<pair<int,int>> constraints;
bool flag = false;
vector<int> ans;

void solve(int dia, int restante, vector<int> possibilities) {
    if (dia == D) {
        if (restante == 0) {
            flag = true;
            ans.clear();
            for (int i = 0; i < possibilities.size(); i++) {
                ans.push_back(possibilities[i]);
            }
            return;
        }
    } else {
        for (int i = constraints[dia].first; i <= constraints[dia].second; i++) {
            possibilities.push_back(i);
            solve(dia + 1, restante - i, possibilities);
            possibilities.pop_back();
        }
    }
}


int main(int argc, char** argv)
{
    optimize;
    cin >> D >> SUM;
    constraints.resize(D);

    for (int i = 0; i < D; i++) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    vector<int> p;

    solve(0, SUM, p);

    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}