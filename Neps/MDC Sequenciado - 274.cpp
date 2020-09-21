#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a % b);
}


int main(int argc, char const *argv[]){
    int N, x;
    int MDC = 0;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x;

        MDC = mdc(MDC, x);
    }
    cout << MDC << endl;
    return 0;
}