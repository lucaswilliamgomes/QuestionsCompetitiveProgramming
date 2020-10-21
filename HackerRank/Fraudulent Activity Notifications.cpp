#include <bits/stdc++.h>

using namespace std;


//    TLE
float median (vector<int> espace) {
    sort(espace.begin(), espace.end());
    int tam = espace.size();
    if (tam % 2 == 0){
        return ((espace[tam/2] + espace[(tam/2)+1]) / 2);
    } else {
        return (espace[ceil(tam/2)]);
    }
}
// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int ans = 0;
    
    vector <int> espace (d);
    for (int i = d;i < expenditure.size(); i++){
        
    }
    return ans;

}

int main () {
    vector <int> expenditures; 
    int d, n, aux;
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> aux;
        expenditures.push_back(aux);  
    }

    m
    cout << activityNotifications(expenditures, d) << endl;


    return 0;
}