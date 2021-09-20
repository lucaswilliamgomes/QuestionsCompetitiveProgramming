#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010

using namespace std;

ll values[MAXN], BIT[MAXN], cont = 1;

ll query(int i) {
	ll sum = 0;
	for (; i > 0; i -= ((i) & -(i)))
		sum += BIT[i];
	return sum;
}

void update(int i, int value) {
	for (; i < MAXN; i+= ((i) & -(i)))
		BIT[i] += value;
}

int main(int argc, char const *argv[])
{
    ll n, l, r, k, value;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k >> value;
        for (int j = 0; j < k; j++) {
            values[cont] = value;
            cont++;
        }
    }
    for (int i = 1; i < cont; i++) {
        update(i, values[i]);
        //cout << BIT[i] << endl;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        cout << query(r) - query(l-1) << endl;
    }

    return 0;
}

