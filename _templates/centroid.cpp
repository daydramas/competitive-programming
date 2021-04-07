int hd[N], nx[M], to[M], ei = 0;
 
inline void link(int i, int j) {
	nx[++ei] = hd[i], hd[i] = ei, to[ei] = j;
}
 
int n, k, ss[N];
bool vv[N];
 
int subtree(int x, int p = 0) {
	ss[x] = 1;
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p)
			ss[x] += subtree(y, x);
	return ss[x];
}
 
int centroid(int dd, int x, int p = 0) {
	for (int j = hd[x], y; j; j = nx[j])
		if (!vv[y = to[j]] && y != p && ss[y] > dd)
			return centroid(dd, y, x);
	return x;
}
 
void decomp(int x = 1) {
	int c = centroid(subtree(x) / 2, x);
	// do smth
	vv[c] = 1;
	for (int j = hd[c], y; j; j = nx[j])
		if (!vv[y = to[j]])
			decomp(y);
}
 