#include <bits/stdc++.h>

using namespace std;

int values[100010], BIT[100010];

int query(int i) {
	int sum = 0;
	for (; i > 0; i -= ((i) & -(i)))
		sum += BIT[i];
	return sum;
}

void update(int i, int value) {
	for (; i < 100010; i+= ((i) & -(i)))
		BIT[i] += value;
}

int main(int argc, char const *argv[])
{
    int N, Q, t, p, l, r;
    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> p;
            update(p, 1);
        } else {
            cin >> l >> r;
            cout << query(r) - query(l-1) << endl;
        }
    }
    return 0;
}
