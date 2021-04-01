const int S = 1 << 18;

int tt[S << 1];

void update(int i, int x, int k = 1, int l = 0, int r = S - 1) {
	if (l == r) { tt[k] = x; return; }
	int m = (l + r) >> 1;
	if (i <= m) update(i, x, k << 1, l, m); 
	else update(i, x, k << 1 | 1, m + 1, r);
	tt[k] = tt[k << 1] + tt[k << 1 | 1];
}

int query(int ql, int qr, int k = 1, int l = 0, int r = S - 1) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return tt[k];
	int m = (l + r) >> 1;
	int q1 = query(ql, qr, k << 1, l, m);
	int q2 = query(ql, qr, k << 1 | 1, m + 1, r);
	return q1 + q2;
}