#define ll long long 

ll values[100050], BIT[100050];

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
