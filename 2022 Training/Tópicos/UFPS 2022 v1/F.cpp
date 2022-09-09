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
    
    string a;
    cin >> a;
    int cont_coluna = 0;
    int cont_linha = 0;
    char board[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = '0';
        }
    }
    for (auto it: a) {
        if (cont_coluna == 8) {
            cont_coluna = 0;
        }
        if (it == '/') {
            cont_linha++;
            cont_coluna = 0;
            continue;
        }

        if (isdigit(it)) {
            cont_coluna += it-'0';
            continue;
        }

        board[cont_coluna][cont_linha] = it;
        cont_coluna++;
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 7; j >= 0; j--) {
            cout << board[i][j];
            if (j != 0) cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
