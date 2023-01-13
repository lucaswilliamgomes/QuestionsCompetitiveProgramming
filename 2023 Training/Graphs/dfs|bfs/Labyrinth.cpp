#include <bits/stdc++.h>
#define MAXNM 1010

using namespace std;

int n, m;
char graph[MAXNM][MAXNM];
bool visiteds[MAXNM][MAXNM];
pair<int, int> start, end_;

bool verifyConstraints(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and graph[i][j] != '#');
}


string bfs() {
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    visiteds[start.first][start.second] = true;

    bool find = false;

    while (!find && !q.empty()) {
        auto p = q.front();
        q.pop();

        if (verifyConstraints(p.first + 1, p.second) && !visiteds[p.first + 1][p.second]) {
            q.push({p.first + 1, p.second});
            visiteds[p.first + 1][p.second] = true;
            graph[p.first + 1][p.second] = 'D';
            if (p.first + 1 == end_.first && p.second == end_.second) find = true;
        }

        if (verifyConstraints(p.first - 1, p.second) && !visiteds[p.first - 1][p.second]) {
            q.push({p.first - 1, p.second});
            visiteds[p.first - 1][p.second] = true;
            graph[p.first - 1][p.second] = 'U';
            if (p.first - 1 == end_.first && p.second == end_.second) find = true;
        }

        if (verifyConstraints(p.first, p.second + 1) && !visiteds[p.first][p.second + 1]) {
            q.push({p.first, p.second + 1});
            visiteds[p.first][p.second + 1] = true;
            graph[p.first][p.second + 1] = 'R';
            if (p.first == end_.first && p.second + 1 == end_.second) find = true;
        }

        if (verifyConstraints(p.first, p.second - 1) && !visiteds[p.first][p.second - 1]) {
            q.push({p.first, p.second - 1});
            visiteds[p.first][p.second - 1] = true;
            graph[p.first][p.second - 1] = 'L';
            if (p.first == end_.first && p.second - 1 == end_.second) find = true;
        }
    }

    if (!find) return "";

    string ans = "";
    int i = end_.first, j = end_.second;

    while (graph[i][j] != 'A') {

        if (graph[i][j] == 'U') {
            ans.push_back('U');
            i++;
        } else if (graph[i][j] == 'D') {
            ans.push_back('D');
            i--;
        } else if (graph[i][j] == 'R') {
            ans.push_back('R');
            j--;
        } else if (graph[i][j] == 'L') {
            ans.push_back('L');
            j++;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        for (int j = 0; j < m; j++) {
            if (aux[j] == 'A') start = {i, j};
            if (aux[j] == 'B') end_ = {i, j};
            graph[i][j] = aux[j];
        }
    }

    string ans = bfs();
    
    if (ans.size()) {
        cout << "YES" << endl << ans.size() << endl << ans << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
