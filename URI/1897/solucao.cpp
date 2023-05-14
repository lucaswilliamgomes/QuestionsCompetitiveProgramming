#include <bits/stdc++.h>

using namespace std;

int bfs(int currentValue, int expectedValue)
{
  queue<pair<int, int>> q;
  unordered_map<int, bool> memo;
  q.push({currentValue, 0});

  while (true)
  {
    auto current = q.front();
    if (current.first == expectedValue)
      return current.second;
    q.pop();

    if (!memo[(current.first * 2)])
    {
      memo[(current.first * 2)] = true;
      q.push({current.first * 2, current.second + 1});
    }

    if (!memo[(current.first * 3)])
    {
      memo[(current.first * 3)] = true;
      q.push({current.first * 3, current.second + 1});
    }

    if (!memo[(current.first / 2)])
    {
      memo[(current.first / 2)] = true;
      q.push({current.first / 2, current.second + 1});
    }

    if (!memo[(current.first / 3)])
    {
      memo[(current.first / 3)] = true;
      q.push({current.first / 3, current.second + 1});
    }

    if (!memo[(current.first + 7)])
    {
      memo[(current.first + 7)] = true;
      q.push({current.first + 7, current.second + 1});
    }

    if (!memo[(current.first - 7)])
    {
      memo[(current.first - 7)] = true;
      q.push({current.first - 7, current.second + 1});
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << bfs(n, m) << endl;
}
