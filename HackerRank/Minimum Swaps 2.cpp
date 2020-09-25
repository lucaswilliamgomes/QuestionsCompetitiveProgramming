#include <bits/stdc++.h>

using namespace std;
/*        TLE
int minimumSwaps(vector<int> arr) {
    int aux, ans = 0;
    
    int tam = arr.size();

    for (int i = 0; i < tam; i++){
        if (arr[i] != (i+1)){
            for (int j = (i+1); j < tam; j++){
                if ((i+1) == arr[j]) {
                    aux = arr[i];
                    //cout << "Trocando o " << arr[i] << " pelo " << arr[j] << endl; 
                    arr[i] = arr[j];
                    arr[j] = aux;
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;

}*/




int minimumSwaps(vector<int> arr) {
    int tam = arr.size();
    pair <int, int> elemPos[tam];    
    int ans = 0;

    for (int i = 0; i < tam; i++){
        elemPos[i].first = arr[i];
        elemPos[i].second = i+1;
    }
    
    for (int i = 0; i < tam; i++){    
                                                        // 1 2 3 4 5   2 1 3 4 5   2 3 1 4 5   1 2 4 1 5
        if (elemPos[i].first != elemPos[i].second) {    // 2 3 4 1 5   2 3 4 1 5   2 3 4 1 5   2 3 4 1 5
            
            int aux1 = elemPos[i].first;
            int aux2 = elemPos[i].second;

            elemPos[i].second = aux1;

            elemPos[aux2].second = aux1;


            /*for (int j = i; j < tam; j++){
                if (elemPos[i].first == elemPos[j].second){
                    int aux = elemPos[i].second;
                    elemPos[i].second = elemPos[j].second;
                    elemPos[j].second = aux;
                }
            }*/

            /*for (int j = 0; j < tam; j++){
                cout << elemPos[j].first << " " << elemPos[j].second << endl;    
            }*/

            ans++;
        }
    }
    return ans;
}

int main (){
    int n, aux;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> aux;
        arr.push_back(aux);
    }

    cout << minimumSwaps(arr) << endl;

    return 0;
}


//1 2 3 4 5 6 7  1 3 2 4 5 6 7  1 3 5   2  
//1 3 5 2 4 6 7  1 3 5 2 4 6 7  1 3 5 2 4 6 7 
