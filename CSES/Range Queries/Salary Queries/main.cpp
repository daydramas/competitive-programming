#include <bits/stdc++.h>
using namespace std;

using T = int; T U = 0;
T F(T a, T b) { return (a+b); }

struct SegNode {
	T v; struct SegNode* C[2];
	SegNode() { v=0; C[0] = C[1] = nullptr; }
	SegNode* c(int i) {
		if(!C[i]) C[i] = new SegNode();
		return C[i]; }
	void upd(int qi, T qv, int l, int r) {
		if(l==r) { v += qv; return; }
		int m = (l+r)/2;
		if(qi <= m) c(0)->upd(qi,qv,l,m);
		else c(1)->upd(qi,qv,m+1,r);
		v = F((C[0] ? C[0]->v : U),
			(C[1] ? C[1]->v : U)); }
	T qry(int ql, int qr, int l, int r) {
		if(ql <= l && r <= qr) return v;
		else if(qr < l || ql > r) return U;
		int m = (l+r)/2;
		return F((C[0] ? C[0]->qry(ql,qr,l,m) : U),
				(C[1] ? C[1]->qry(ql,qr,m+1,r) : U)); }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, q; char t; int x, y;
	cin >> n >> q;
	vector<int> a(n+1);
	SegNode *root = new SegNode;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		root->upd(a[i],1,1,1e9);
	}
	for(int i=1; i<=q; i++) {
		cin >> t >> x >> y;
		if(t == '?') {
			cout << root->qry(x,y,1,1e9) << '\n';
		} else {
			root->upd(a[x],-1,1,1e9); a[x] = y;
			root->upd(a[x],1,1,1e9);
		}
	}

}