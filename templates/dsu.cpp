const int DSU = (1<<18);
int dd[DSU];

void init() {
	for(int i=0; i<DSU; i++) {
		dd[i] = -1;
	}
}
void get(int x) {
	if(dd[x] < 0) return x;
	return dd[x] = get(dd[x]);
}
bool same(int x, int y) {
	return get(x) == get(y);
}
bool comb(int x, int y) {
	x = get(x), y = get(y);
	if(x == y) return false;
	dd[x] += dd[y]; dd[y] = x;
	return true;
}