#include <bits/stdc++.h>

using namespace std;

int n, t;
vector < pair <int, string> > alunos;
vector <string> times[1005];

int main (){
   
    string name;
    int h;
    
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> name >> h;
        alunos.emplace_back(h, name);
    }

    sort (alunos.begin(), alunos.end());

    n--;
    int cont = 0;
    while (n >= 0){
        times[cont].push_back(alunos[n].second);
        n--;
        if (cont == t-1){
            cont=0;
            continue;
        }
        cont++;
    }

    for(int i = 0; i < t; i++){
        sort(times[i].begin(), times[i].end());
    }

    for(int i = 0; i < t; i++){
        cout << "Time " << i+1 << endl;
        for (int j = 0; j < times[i].size(); j++){
            cout << times[i][j] << endl;
        }    
        cout << endl;
    }

    return 0;
}