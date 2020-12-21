const int maxn = 1e5;

using T = int;
T st[(maxn+5)*2];
T ID=0; T comb(T i, T j) { return i+j; }
void init() {
	for(int i=0; i<maxn*2; i++) st[i]=ID; }
void pull(int i) {
	st[i] = comb(st[i*2], st[i*2+1]); }
void upd(int i, T val) {
	for(st[i+maxn]=val; i>1; i/=2) pull(i/2); }
T qry(int l, int r) {
	T L=ID, R=ID;
	for (l+=maxn, r+=maxn; l<r; l/=2, r/=2) {
		if (l&1) L = comb(L, st[l++]);
		if (r&1) R = comb(R, st[--r]);
	}
	return comb(L, R);
}