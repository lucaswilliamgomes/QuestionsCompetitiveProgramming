#include <bits/stdc++.h>

using namespace std;


bool finder (vector <int> group, int element) {
    bool find = false;
    for (int i = 0; i < group.size(); i++) {
        if (group[i] == element) find = true;
    }

    return find;
}   

bool one (set <int> parte, vector <int> todo) {
    bool existe = false;
    
    for(int it : parte){
        if(finder(todo, it)){
            existe = true;
            return existe;
        }
    }
    return existe;
}   

int main () {
    int friends, days, infected, day_infected;
    cin >> friends >> days;
    cin >> infected >> day_infected;
    int quant, aux;
    vector <int> group;
    set <int> infecteds;
    infecteds.insert(infected);

    for (int i = 0; i < days; i++) {
        cin >> quant;
        for (int f = 0; f < quant; f++){
            cin >> aux;
            group.push_back(aux);
        } 
        if ((i >= (day_infected-1)) and one(infecteds, group)) {   
            for (int i = 0; i < quant; i++){
                infecteds.insert(group[i]);
            }
        };
        group.clear();
    }

    cout << infecteds.size() << endl;  
    return 0;
}