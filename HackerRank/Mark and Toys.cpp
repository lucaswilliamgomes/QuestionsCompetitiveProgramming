#include <bits/stdc++.h>

using namespace std;

// Complete the maximumToys function below.
void maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int sum = 0, ans = 0;
    for (int i = 0; i < prices.size(); i++){
        if (sum + prices[i] <= k){
            sum+= prices[i];
            ans++;
        } else break;
    }

    cout << ans << endl;

}

int main () {
    vector <int> prices;
    int tam, money, aux;
    cin >> tam >> money;

    for (int i = 0; i < tam; i++){
        cin >> aux;
        prices.push_back(aux);
    }

    maximumToys (prices, money);
    return 0;
}