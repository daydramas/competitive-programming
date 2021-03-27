const int N = 69;

struct L {
	int x;
	L *next;
} *aa[N];

void link(int i, int j) {
	L *l = new L();
	l->x = j;
	l->next = aa[i];
	aa[i] = l;
};

int ss[N], vv[N];

int subtree(int x, int p) {
	ss[x] = 1;
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			ss[x] += subtree(y, x);
	return ss[x];
}

int centroid(int dd, int x, int p) {
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p && ss[y->x] >= dd)
			return centroid(dd, y->x, x);
	return x;
}

void decomp(int x) {
	int c = centroid(subtree(x, 0) / 2, x, 0);
	vv[x] = 1;
	// do whatever you gotta do :D
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x])
			decomp(y->x);
}