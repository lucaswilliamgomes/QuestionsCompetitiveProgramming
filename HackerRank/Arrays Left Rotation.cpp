#include <bits/stdc++.h>

using namespace std;

vector<int> rotLeft(vector<int> a, int d) {

    for (int i = 0; i < d ; i++){
        a.push_back(a[i]);
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < d; i++){
        a.pop_back();
    }

    reverse(a.begin(), a.end());
    return a;
}

int main (){    
    int n, r, aux;
    vector <int> a;

    cin >> n >> r;

    for (int i = 0; i < n; i++){
        cin >> aux;
        a.push_back(aux);
    }

    a = rotLeft (a, r);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}