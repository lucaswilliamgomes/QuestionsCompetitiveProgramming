#include <bits/stdc++.h>

using namespace std;

int main () {
int quantCartas, quantTrocas;
cin >> quantCartas >> quantTrocas;
vector<pair<int, int>> cartas(quantCartas);
vector<int> queries(quantCartas + 1);

for (int i = 0; i < quantCartas; i++) {
  cin >> cartas[i].first;
}

for (int i = 0; i < quantCartas; i++) {
  cin >> cartas[i].second;
}

for (int i = 0; i < quantTrocas; i++) {
  int l, r;
  cin >> l >> r;
  queries[l]++;
  queries[r + 1]--;
}

int currentSum = 0;
for (int i = 1; i <= quantCartas; i++) {
  currentSum += queries[i];
  if (currentSum % 2 == 0) {
    cout << cartas[i-1].first << " ";
  } else {
    cout << cartas[i-1].second << " ";
  }
}
cout << endl;
}