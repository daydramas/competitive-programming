
int n, tt[N * 2];

void pull(int i) {
	tt[i] = tt[i << 1] + tt[i << 1 | 1];
}

void update(int i, int x) {
	tt[i += n] = x;
	for (i >>= 1; i; i >>= 1)
		pull(i);
}

int query(int l, int r) {
	int ret = 0;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += tt[l++];
		if (r & 1) ret += tt[--r];
	}
	return ret;
}