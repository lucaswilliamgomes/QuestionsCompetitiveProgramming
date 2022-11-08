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
const double PI = acos(-1);
 
struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
 
    double norm() { return hypot(x, y); }
 
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
 
double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
 
double inner(point p1, point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
 
double cross(point p1, point p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
 
bool ccw(point p, point q, point r)
{
    return cross(q - p, r - p) > 0;
}
 
bool collinear(point p, point q, point r)
{
    return fabs(cross(p - q, r - p)) < EPS;
}
 
point rotate(point p, double rad)
{
    return point(p.x * cos(rad) - p.y * sin(rad),
                p.x * sin(rad) + p.y * cos(rad));
}
 
double angle(point a, point o, point b)
{
    return acos(inner(a - o, b - o) / (dist(o, a) * dist(o, b)));
}
 
point proj(point u, point v)
{
    return v * (inner(u, v) / inner(v, v));
}
 
bool between(point p, point q, point r)
{
    return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}
 
point lineIntersectSeg(point p, point q, point A, point B)
{
    double c = cross(A - B, p - q);
    double a = cross(A, B);
    double b = cross(p, q);
    return ((p - q) * (a / c)) - ((A - B) * (b / c));
}
 
bool parallel(point a, point b)
{
    return fabs(cross(a, b)) < EPS;
}
 
bool segIntersects(point a, point b, point p, point q)
{
    if(parallel(a - b, p - q))
    {
        return between(a, p, b) || between(a, q, b) || between(p, a, q) || between(p, b, q);
    }
    point i = lineIntersectSeg(a, b, p, q);
    return between(a, i, b) && between(p, i, q);
}
 
point closestToLineSegment(point p, point a, point b)
{
    double u = inner(p - a, b - a) / inner(b - a, b - a);
    if(u < 0.0) return a;
    if(u > 1.0) return b;
    return a + ((b - a) * u);
}
 
int main(int argc, char **argv)
{
    optimize;
    #ifdef ONLINE_JUDGE
	freopen("angle2.in", "r", stdin);
	freopen("angle2.out", "w", stdout);
	#endif

    

    return 0;
}