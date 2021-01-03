template<class T> struct BIT {
	int N; T *B;
	BIT() {}
	BIT(int N) { this->N=N; B = new T[N+1]; }
	void upd(int i, T V) { for(; i<N; i+=i&(-i)) B[i]+=V; }
	T qry(int i) { T R=0; for(; i; i-=i&(-i)) R+=B[i];
		return R; }
	T qry(int l, int r) { return qry(r)-qry(l-1); }
};