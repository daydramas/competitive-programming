int hh[N], nn[M], tt[M], ei = 0;

inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}