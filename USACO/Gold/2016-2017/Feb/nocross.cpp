#include <bits/stdc++.h>

using namespace std;

// defines
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f(i, a, b) for(ll i = a; i < b; i++)
#define rf(i, a, b) for(ll i = a; i >= b; i--)
#define w(a) while(a--)
#define arrin(a,n) f(i,0,n) { cin >> a[i]; }
#define arrin1(a,n) f(i,1,n+1) { cin >> a[i]; }
#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }

// structures
struct segTree {

	int n;
	vector<int> st;

	segTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		build(1, 1, n);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = 0;
			return;
		}
		build(left(id), L, (L+R)/2);
		build(right(id), (L+R)/2+1, R);
		st[id] = max(st[left(id)],st[right(id)]);
	}

	void update(int id, int L, int R, int P, int value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) st[id] = value;
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
		st[id] = max(st[left(id)], st[right(id)]);
	}

	void update(int P, int value) {
		update(1, 1, n, P, value);
	}

	int get(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return max(get(left(id), L, (R+L)/2, l, r),get(right(id), (R+L)/2+1, R, l, r));
	}

	int get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};
// global variables
int n;
int A[100005],B[100005];
vector<int> c;
// functions
int main() {

	// local variables

	// input
	fastio;
	cin >> n;
	f(i,1,n+1) {
		cin >> A[i];
	}
	f(i,1,n+1) {
		int b;
		cin >> b; B[b] = i;
	}
	segTree t(n);

	// main
	int ans = 0;
	f(i,1,n+1) {
		c.clear();
		f(j,max(1,A[i]-4), min(n, A[i]+4)+1) {
			c.push_back(B[j]);
		}
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		for (int ci : c) {
			int q = t.get(1, ci);
			ans = max(ans, q+1);
			t.update(ci+1,q+1);
		}
	}

	// output
	cout <<ans << endl;
	return 0;
}
