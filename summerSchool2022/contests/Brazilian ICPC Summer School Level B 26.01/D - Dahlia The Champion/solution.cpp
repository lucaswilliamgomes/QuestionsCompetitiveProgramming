#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Point
{
    int x;
    int y;
    Point() {}
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

ll dist(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool hasSameSignal(Point a, Point b)
{
    if (a.x > 0 && b.x > 0 && a.y > 0 && b.y > 0)
        return true;
    else if (a.x < 0 && b.x < 0 && a.y > 0 && b.y > 0)
        return true;
    else if (a.x < 0 && b.x < 0 && a.y < 0 && b.y < 0)
        return true;
    else if (a.x > 0 && b.x > 0 && a.y < 0 && b.y < 0)
        return true;
    return false;
}

int getSlope(Point begin, Point a)
{
    int deltaY1 = a.y - begin.y;
    return (deltaY1 == 0 ? 0 : (a.x - begin.x) / deltaY1);
}

int main()
{
    Point begin = Point();
    int R, N, res = 0;
    unordered_map<int, vector<Point>> targets;
    cin >> begin.x >> begin.y >> R >> N;
    for (int i = 0; i < N; i++)
    {
        Point target = Point();
        cin >> target.x >> target.y;
        auto slope = getSlope(begin, target);

        if (targets[slope].size())
        {
            for (int j = 0; j < targets[slope].size(); j++)
            {
                if (hasSameSignal(targets[slope][j], target))
                {
                    if (dist(begin, target) < dist(begin, targets[slope][j]))
                    {
                        targets[slope][j] = target;
                    }
                }
                if (j == targets[slope].size() - 1) {
                    targets[slope].push_back(target);
                    break;
                }
            }
        }
        else
        {
            targets[slope].push_back(target);
        }
    }

    for (auto it : targets)
    {   
        for (auto v: it.second) {
            if (dist(begin, v) <= R) {
                res++;
            }
        }
    }
    cout << res << endl;

    return 0;
}