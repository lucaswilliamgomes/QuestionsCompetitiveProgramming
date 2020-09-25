#include  <bits/stdc++.h>

using namespace std;

long long aVeryBigSum(vector<long long> ar) {
    long long sum = 0;

    for (long long i = 0; i < ar.size(); i++){
        sum += ar[i];
    }

    return sum;
}




int main (){
    long long n, aux;
    vector <long long> ar;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> aux;
        ar.push_back(aux);
    }

    cout << aVeryBigSum(ar) << endl;



    return 0;
}