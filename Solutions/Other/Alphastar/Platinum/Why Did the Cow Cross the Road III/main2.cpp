#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string s = "") {
	cin.tie(0)->sync_with_stdio(0); if (s.size()) {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout); }
}

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
int n, k, a[N], b[N];

template<class T> struct BIT {

	struct Node {
		Tree<int> t;
		void ins(int val) { t.insert(val); }
		T get(int x) {
			int a = t.order_of_key(max(0, x-k));
			int b = t.size() - t.order_of_key(min(x+k+1,n+1));
			return a+b;
		}
	};
	vector<Node> a;

	BIT() {}
	BIT(int n) { a.resize(n+1); }

	T qry(int pos, int x) {
		T res = 0;
		for(int i=pos; i; i-=i&(-i)) res += a[i].get(x);
		return res;
	}
	void upd(int pos, int val) {
		for(int i=pos; i<=n; i+=i&(-i)) a[i].ins(val);
	}
};
BIT<ll> bit;

int main() {
	setIO("friendcross");

	ll ans = 0; int x;
	scanf("%d%d", &n, &k);
	bit = BIT<ll>(n);
	for(int i=n; i>=1; i--) {
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++) { 
		scanf("%d", &x); b[x] = i; 
	}
	for(int i=1; i<=n; i++) { 
		x = a[i];
		ans += bit.qry(b[x], x);
		bit.upd(b[x], x);
	}
	printf("%lld\n", ans);
}