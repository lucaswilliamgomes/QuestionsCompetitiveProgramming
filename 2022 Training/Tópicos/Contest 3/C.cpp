#include <bits/stdc++.h>

using namespace std;

struct Pointer
{
    int x, y;

    Pointer(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Pointer &a)
    {
        if (a.x == x) return (a.x==x && a.y<y);
        else return a.x > x;
    }
};


int main(int argc, char const *argv[])
{
    int n, t;
    set<Pointer> ar;
    cin >> t;
    while(t--) {
        vector<Pointer> ar;
        cin >> n;
        while (n--) {
            int x, y;
            Pointer el;
            scanf("%d %d", &x, &y);
            //cin >> x >> y;
            el.x = x;
            el.y = y;
            ar.push_back(el);
        }

        sort(ar.begin(), ar.end());

        for(auto it : ar) {
            printf("%d %d\n", it.x, it.y);
        }
    }
   

    return 0;
}
