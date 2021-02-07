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

const int maxn = 1e6+5;
int n, k;
ll x, d[maxn], p[maxn], rp[maxn];


int main() {
	IO("");

	cin >> n >> x >> k;
	FOR(i,1,n) cin >> d[i];
	p[0] = rp[n+1] = 0;
	FOR(i,1,n) p[i] = p[i-1] + d[i];
	ROF(i,1,n) rp[i] = rp[i+1] + d[i];
	
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* template by bqi343
*/