#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

struct jobProfit {
    bool operator()(Job const& a, Job const& b)
    {
        return (a.profit < b.profit);
    }
};

vector<int> JobScheduling(Job arr[], int n) 
{ 
    vector<Job> ans;
    vector<int> result;
    sort(arr, arr+n, [](Job a, Job b) { return a.dead < b.dead; });

    priority_queue<Job, vector<Job>, jobProfit> pq;
    
    for (int i = n - 1; i >= 0; i--) {
        int store;

        if (i == 0) {
            store = arr[i].dead;
        } else {
            store = arr[i].dead - arr[i-1].dead;
        }

        pq.push(arr[i]);

        while (store > 0 && pq.size() > 0) {
            ans.push_back(pq.top());
            pq.pop();
            store--;
        }
    }

    sort(ans.begin(), ans.end(), [](Job a, Job b) { return a.dead < b.dead;});
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i].profit;
    }
    result.push_back(ans.size());
    result.push_back(sum);
 
    return result;
} 

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Job arr[n];

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }

        vector<int> ans = JobScheduling(arr, n);

        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }


    return 0;
}