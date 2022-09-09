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

int cont_minutes(int h_bed, int m_bed, int h, int m) {
    if (h_bed == h) {
        if (m >= m_bed) {
            return m-m_bed;
        } else {
            return 23 * 60 + (60 - (m_bed - m));
        }
    }
    int cont_h = 0, cont_min = 0;
    for (int i = h_bed; ; i++) {
        if (i == 24) i=0;
        if (i == h) break;
        cont_h++;
    }

    if (m_bed <= m) {
        cont_min = m - m_bed;
    } else {
        cont_min = 60 - (m_bed - m);
        cont_h -= 1;
    }
    return cont_h * 60 + cont_min;
}


int main(int argc, char** argv)
{
    optimize;

    // int min_alarm = cont_minutes(0, 10, 0, 5);

    // int ans_h = min_alarm / 60;
    // int ans_m = min_alarm % 60;

    // cerr << ans_h << " " << ans_m << endl;

    int t;
    cin >> t;
    while (t--) {

        int cont_alarms, hr_to_bed, min_to_bed;
        cin >> cont_alarms >> hr_to_bed >> min_to_bed;

        int min_alarm = INT16_MAX;

        for (int i = 0; i < cont_alarms; i++) {
            int h, m;
            cin >> h >> m;
            min_alarm = min(min_alarm, cont_minutes(hr_to_bed, min_to_bed, h, m));
        }

        int ans_h = min_alarm / 60;
        int ans_m = min_alarm % 60;

        cout << ans_h << " " << ans_m << endl;
    }

    return 0;
}