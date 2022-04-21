#include <bits/stdc++.h>

using namespace std;

struct Meet
{
    int start;
    int end;

    bool operator<(const Meet &a)
    {
        return end < a.end;
    }
};

int maxMeetings(int start[], int end[], int n)
{
    vector<Meet> meets(n);
    for (int i = 0; i < n; i++) {
        meets[i].start = start[i];
        meets[i].end = end[i];
    }

    sort(meets.begin(), meets.end());

    vector<Meet> a;
    for (int i = 0; i < n; i++) {
        if (a.size() > 0) {
            if (a.back().end < meets[i].start) {
                a.push_back(meets[i]);
            }
        } else {
            a.push_back(meets[i]);
        }
    }
    return a.size();
}

int main(int argc, char const *argv[])
{
    int start[100010];
    int end[100010];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }

    cout << maxMeetings(start, end, n);

    return 0;
}
