#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int current = 0, totalGas = 0, totalCost = 0, currentGas = 0, ans = 0;
    while (current < gas.size()) {
        totalGas += gas[current];
        totalCost += cost[current];
        currentGas += (gas[current] - cost[current]);

        if (currentGas < 0) {
            currentGas = 0;
            ans = current + 1;
        }

        current += 1;
    }

    if (totalGas >= totalCost) return ans;
    else return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> gas(n), custo(n);

    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> custo[i];
    }

    cout << canCompleteCircuit(gas, custo) << endl;

    return 0;
}
