struct L {
	int x; L *next;
	L(int x, L *next) : x(x), next(next) {}
} *aa[N];

void link(int i, int j) {
	L *l = new L(j, aa[i]);
	aa[i] = l;
};