template<class T> struct RMQ {
	int N; T *st; RMQ() {}
    T ID=1e9; T comb(T i, T j) { return min(i,j); }
	RMQ(int N) { this->N = N;
		st = new T[(N+1)*4]; }
    void upd(int I, T v) { upd(I,v,1,1,N); }
    void upd(int I, T v, int i, int l, int r) {
        if(l==r) st[i]=v; int m=(l+r)/2;
        if(l<=I && I<=m) upd(I,v,i*2,l,m);
        if(m+1<=I && I<=r) upd(I,v,i*2+1,m+1,r);
        st[i] = min(st[i*2], st[i*2+1]); }
    T qry(int L, int R) { return qry(L,R,1,1,N); }
    T qry(int L, int R, int i, int l, int r) {
        if(L<=l && r<=R) return st[i]; int m=(l+r)/2;
        return min(qry(L,R,i*2,l,m),qry(L,R,i*2+1,m+1,r)); }
};