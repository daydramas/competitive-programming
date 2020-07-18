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
#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }

// structures

// global variables
int n;
pll p[100005];
int bit[100005];
vector<int> ch[100005];
pii interval[100005];
int t;
int ans[100005];
// functions
int dfs(int i) {
	interval[i].first = ++t;
	int sz = 1;
	f(j, 0, ch[i].size()){
		sz += dfs(ch[i][j]);
	}
	interval[i].second = interval[i].first+sz-1;
	return sz;
}
void update(int i, int val) {
	for (; i<=n; i+=i&(-i)) {
		bit[i] += val;
	}
}
int sum(int i) {
	int sum = 0;
	for (; i>0; i-=i&(-i)) {
		sum += bit[i];
	}
	return sum;
}
int main() {

	// local variables

	// input
	fastio;
	cin >> n;
	f(i, 0, n) {
		ll a; cin >> a;
		p[i] = pll(a, i+1);
	}
	f(i, 1, n) {
		int a; cin >> a;
		ch[a].push_back(i+1);
	}
	// main
	t=0; dfs(1);
	sort(p, p+n);
	f(i, 1, n+1) bit[i] = 0;
	rf(i, n-1, 0) {
		int i_ = p[i].second;
		ans[i_] = sum(interval[i_].second)-sum(interval[i_].first);
		update(interval[i_].first, 1);

	}
	// output
	f(i, 1, n+1) cout << ans[i] << endl;
	return 0;
}
