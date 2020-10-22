#include <bits/stdc++.h>

using namespace std;

vector <int> grafo [100005];
vector <int> ans;

bool finder (vector <int> iterador, int value){
    for (int i = 0; i < iterador.size(); i++){
        if (iterador[i] == value){
            return true;
        }
    }

    return false;
}

int main () {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int T, A, B;
        cin >> T >> A >> B;

        if (T == 0){
            if (finder(grafo[A], B)) ans.push_back(1);
            else ans.push_back(0);
        } else {
            grafo[A].push_back(B);
            grafo[B].push_back(A);
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}