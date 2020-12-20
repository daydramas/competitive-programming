const int maxn = 1e5;

using T = int;
T bit[maxn+5];
void upd(int i, T value) {
	for(; i<maxn; i+=i&(-i)) bit[i] += value;
}
T qry(int i) {
	T sum=0;
	for(; i>0; i-=i&(-i)) sum += bit[i];
	return sum;
}