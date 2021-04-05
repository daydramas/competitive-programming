int hd[N], nx[M], to[M], ei = 0;

inline void link(int i, int j) {
	nx[++ei] = hd[i], hd[i] = ei, to[ei] = j;
}

/*

usage

for (int j = hd[x], y; j; j = nx[j]) {
	y = to[j];
}

*/