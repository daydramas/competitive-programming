int bit[N];

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}

void update(int i, int x) {
	while (i < N) {
		bit[i] += x;
		i += i & (-i);
	}
}