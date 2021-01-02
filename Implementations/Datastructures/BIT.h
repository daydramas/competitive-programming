const int maxn = 1e5;

using T = int; T B[maxn+5];
void init() { for(int i=0; i<=maxn; i++) B[i]=0; }
void upd(int i, T V) { for(; i<maxn; i+=i&(-i)) B[i]+=V; }
T qry(int i) { T R=0; for(; i; i-=i&(-i)) R+=B[i];
	return R; }