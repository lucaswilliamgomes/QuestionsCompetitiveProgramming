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
const ld eps = 1e-9;

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}
// a8b7d6
struct pt
{ // ponto
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    bool operator<(const pt p) const
    {
        if (!eq(x, p.x))
            return x < p.x;
        if (!eq(y, p.y))
            return y < p.y;
        return 0;
    }
    bool operator==(const pt p) const
    {
        return eq(x, p.x) and eq(y, p.y);
    }
    pt operator+(const pt p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt p) const { return pt(x - p.x, y - p.y); }
    pt operator*(const ld c) const { return pt(x * c, y * c); }
    pt operator/(const ld c) const { return pt(x / c, y / c); }
    ld operator*(const pt p) const { return x * p.x + y * p.y; }
    ld operator^(const pt p) const { return x * p.y - y * p.x; }
    friend istream &operator>>(istream &in, pt &p)
    {
        return in >> p.x >> p.y;
    }
};

// 7ab617
struct line
{ // reta
    pt p, q;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
    friend istream &operator>>(istream &in, line &r)
    {
        return in >> r.p >> r.q;
    }
};

// c684fb
ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

// 1b1d4a
ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

// 1b72e1
ld disttoline(pt p, line r) { // distancia do ponto a reta
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

int main(int argc, char **argv)
{
    optimize;
    int n, k;

    cin >> n >> k;
    int len = (n * (n - 1)) / 2;
    vector<double> dists;
    vector<line> lines;
    vector<pt> pts(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pt ponto = pt(x, y);
        pts[i] = ponto;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            line ln = line(pts[i], pts[j]);
            lines.push_back(ln);
        }
    }

    pt zero = pt(0, 0);

    cout << fixed;
    cout << setprecision(6) << endl;
    
    for (int i = 0; i < (int)lines.size(); i++) {
        dists.push_back(disttoline(zero, lines[i]));
    }

    sort(ALL(dists));

    cout << dists[k - 1] << endl;



    return 0;
}