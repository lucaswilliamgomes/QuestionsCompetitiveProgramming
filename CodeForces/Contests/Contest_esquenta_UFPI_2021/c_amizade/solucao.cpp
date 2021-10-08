#include <bits/stdc++.h>

using namespace std;

int casas[10010];

int main(int argc, char const *argv[])
{
    int N, rose, distAtual, ans = 0;
    cin >> N >> rose >> distAtual;

    for (int i = 0; i < N; i++) {
        cin >> casas[i];
    }

    int dist;
    
    for (int i = 0; i < N; i++) {
        dist = casas[i] - rose;
        if (dist < 0) dist *= -1;
        if ( dist  <= distAtual) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
