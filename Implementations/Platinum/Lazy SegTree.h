const int maxn = 1e5;

using T = int;
T st[(maxn+5)*2], lz[(maxn+5)*2];
T ID=0; T ID=0; T comb(T i, T j) { return i+j; }
void init() {
	for(int i=0; i<maxn*2; i++) st[i]=lz[i]=ID; }
void pull(int i) {
	st[i] = comb(st[i*2],st[i*2+1]); }
void push(int i, int l, int r) {
	st[i]+=(r-l+1)*lz[i];
	if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
	lz[i]=0;
}
void upd(int L, int R, T v, int i=1, int l=0, int r=maxn) {
	push(i,l,r); if(R<l || L>r) return;
	if(L<=l && R>=r) { lz[i]=v; push(i,l,r); return; }
	int m=(l+r)/2; upd(L,R,v,i*2,l,m);
	upd(L,R,v,i*2+1,m+1,r); pull(i);
}
T qry(int L, int R, int i=1, int l=0, int r=maxn) {
	push(i,l,r); if(R<l || L>r) return ID;
	if(L<=l && R>=r) return st[i]; int m=(l+r)/2;
	return comb(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r));
}