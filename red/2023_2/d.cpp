#include <bits/stdc++.h>
#define int long long
using namespace std;

int orientation(vector<int> a, vector<int> b, vector<int> c) {
    int v = a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(vector<int> a, vector<int> b, vector<int> c) {
    int o = orientation(a, b, c);
    return o < 0;
}

vector<vector<int>> convex_hull(vector<vector<int>>& p) {
    stack<vector<int>> st;
    for (int i = 0; i < 2 && i < p.size(); ++i) st.push(p[i]);
    for (int i = 2; i < p.size(); ++i) {
        vector<int> c = p[i];
        vector<int> b = st.top();
        st.pop();
        vector<int> a = st.top();
        st.pop();
        if (orientation(a, b, c) == 0) {
            st.push(a);
            st.push(c);
            continue;
        }
        while (cw(a, b, c) && !st.empty()) {
            b = a;
            a = st.top();
            st.pop();
        }
        st.push(a);
        st.push(b);
        st.push(c);
    }
    vector<vector<int>> out;
    out.reserve(st.size());
    while (!st.empty()) {
        out.push_back(st.top());
        st.pop();
    }
    reverse(out.begin(), out.end());
    return out;
}

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(2));
    for (auto &x : p) cin >> x[0] >> x[1];
    sort(p.begin(), p.end());
    vector<vector<int>> down = convex_hull(p);
    reverse(p.begin(), p.end());
    vector<vector<int>> up = convex_hull(p);
    int ans {4};
    for (int i = 0; i < down.size() - 1; ++i)
        ans += max(abs(down[i][0] - down[i + 1][0]), abs(down[i][1] - down[i + 1][1]));
    for (int i = 0; i < up.size() - 1; ++i)
        ans += max(abs(up[i][0] - up[i + 1][0]), abs(up[i][1] - up[i + 1][1]));
    reverse(up.begin(), up.end());
    if (down == up && down.size() == 2 && abs(down[0][0] - down[1][0]) == abs(down[0][1] - down[1][1]))
        ++ans;
    cout << ans << '\n';
}