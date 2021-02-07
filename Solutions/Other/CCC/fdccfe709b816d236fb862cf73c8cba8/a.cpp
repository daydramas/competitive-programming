/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-06
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define F			first
#define S			second
#define SZ(x)		int((x).size())
#define ALL(x)		(x).begin(), (x).end()
#define PB			push_back
#define FOR(i,x,y)	for(int i=(x); i<=(y); i++)
#define F0R(i,x)	FOR(i, 0, (x)-1)
#define ROF(i,x,y)	for(int i=(y); i>=(x); i--)
#define R0F(i, x)	ROF(i, 0, (x)-1)
#define EACH(i,x)	for(auto& i : (x))

template<class T> bool ckmin(T& a, const T &b) {
	return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T& a, const T &b) {
	return (b > a ? a = b, 1 : 0); }

void dbg() { cerr << endl; }
template<class T, class ...U> void dbg(const T& t, const U&... u) {
	cerr << ' ' << t; dbg(u...); }
#ifdef LOCAL
	#define DBG(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]:", dbg(__VA_ARGS__)
#else
	#define DBG(...) 0
#endif

void IO(string s = "") {
	cin.tie(0)->sync_with_stdio(0);
	if(SZ(s)) {
		freopen((s+".in").c_str(),"r",stdin); 
		freopen((s+".out").c_str(),"w",stdout);
	}
}

const int maxn = 1e5+5;

int n;
int a[maxn], v[maxn];
vi used;

int cycle(int x) {
	if(v[x]) return 0;
	v[x] = 1;
	used.PB(x);
	return 1 + cycle(a[x]);
}

int main() {
	IO("robdan");

	cin >> n;
	FOR(i,1,n) cin >> a[i];

	ll m = 1;
	int sz[n+1];
	FOR(i,1,n) if(!v[i]) {
		used.clear();
		ll s = cycle(i);
		EACH(x, used) sz[x] = s;
		m = m / __gcd(m, s) * s;
	}
	map<int, map<int,int> >marked;
	ll op = 12e7/n;
	ll mm = m;
	srand (time(NULL));
	F0R(i,rand() % (n*10)) srand(rand());
	while(op--) {
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		if(x == y) continue;
		if(marked[sz[x]][sz[y]]) continue;
		marked[sz[x]][sz[y]] = 1;
		ll m2 = 1;
		swap(a[x], a[y]);
		memset(v, 0, sizeof(v));
		FOR(i,1,n) if(!v[i]) {
			ll s = cycle(i);
			m2 = m2 / __gcd(m2, s) * s;
			if(m2 > mm) break;
		}
		mm = min(mm, m2);
		swap(a[x], a[y]);
	}
	ll div = __gcd(m, mm);
	cout << mm/div << ' ' << m/div << '\n';
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* template by bqi343
*/