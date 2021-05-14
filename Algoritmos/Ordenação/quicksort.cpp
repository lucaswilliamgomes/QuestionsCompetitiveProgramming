#include <bits/stdc++.h>

using namespace std;

vector <int> arr;

int partition (int start, int end) {
    int pivo = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++){
        if (arr[j] < pivo) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[end]);
    return i+1;
}

void quicksort(int start, int end) {
    if (start < end) {
        int pivo = partition(start, end);
        quicksort(start, pivo-1);
        quicksort(pivo+1, end);
    }
}

int main(int argc, char const *argv[]){
    int n, aux;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> aux;
        arr.push_back(aux);
    }

    quicksort(0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
