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
 
#define EPS 1e-9

struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
 
    double norm()
	{
		return sqrt(x*x + y*y);
	}
 
    point normalized()
    {
        return point(x, y) * (1.0 / norm());
    }
 
    double angle() { return atan2(y, x); }
 
    double polarAngle()
    {
        double a = atan2(y, x);
        return a < 0 ? a + 2 * acos(-1.0) : a;
    }
 
    bool operator < (point other) const
    {
        if(fabs(x - other.x) > EPS) return x < other.x;
        else return y < other.y;
    }
 
    bool operator == (point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
 
    point operator + (point other) const
    {
        return point(x + other.x, y + other.y);
    }
 
    point operator - (point other) const
    {
        return point(x - other.x, y - other.y);
    }
 
    point operator * (double k) const
    {
        return point(x * k, y * k);
    }
};

double inner(point p1, point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
 
vector<point> points;
 
int main(int argc, char **argv)
{
    optimize;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        point a;
        cin >> a.x >> a.y;
        points.push_back(a);
    }

    pair<int, int> ans;
    int minAngle = INT32_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            point p1 = points[i];
            point p2 = points[j];
            double angle = abs(acos(inner(p1, p2) / (p1.norm() * p2.norm())));
            
            if (angle < minAngle) {
                minAngle = angle;
                ans = make_pair(i + 1, j + 1);
            }
        }
    }

    cout << ans.first << " " << ans.second << endl;



    return 0;
}