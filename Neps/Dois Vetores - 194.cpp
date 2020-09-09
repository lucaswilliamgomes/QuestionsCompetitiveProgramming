#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    int aux;
    vector<int> pair;
    vector<int> odd;

    for (int x = 0; x < 10; x++){
        cin >> aux;
        if(aux % 2 == 0) pair.push_back(aux);
        else odd.push_back(aux);
    }
    for (int x = 0; x < pair.size(); x++){
        cout << pair[x] << " ";
    }
    cout << endl;
    for (int x = 0; x < odd.size(); x++){
        cout << odd[x] << " ";
    }
    return 0;
}
