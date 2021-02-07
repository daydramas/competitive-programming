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
	#ifndef LOCAL
		if(!SZ(s)) return;
		freopen((s+".in").c_str(),"r",stdin); 
		freopen((s+".out").c_str(),"w",stdout);
	#endif
}

const int N = 1<<18;

int n, m, p[N], cnt[N];
vi g[N], rg[N];
queue<int> q;

void merge(int a, int b) {
	// start from parent
	a = p[a], b = p[b];
	// small to large
	if(SZ(rg[a]) < SZ(rg[b])) swap(a,b);
	// set each child's parent to a, 
	// push into children of a
	EACH(t, rg[b]) p[t] = a, rg[a].PB(t);
	// insert the children of b into a
	g[a].insert(end(g[a]), ALL(g[b]));
	// clear b (for space)
	g[b].clear();
	// insert into queue if more children
	// need to be merged
	if(SZ(g[a]) > 1) q.push(a);
}

int main() {
	IO("fcolor");

	cin >> n >> m;
	F0R(i,m) {
		int a,b; 
		cin >> a >> b;
		g[a].PB(b);
	}
	FOR(i,1,n) {
		// set parents to itself
		rg[i].PB(i);
		p[i] = i;
		// if multiple children, push to queue
		if(SZ(g[i]) > 1) q.push(i);
	}
	while(SZ(q)) {
		int i = q.front(); 
		if(SZ(g[i]) < 2) { q.pop(); continue; }
		// x = first child to merge
		int x = g[i].back(); g[i].pop_back();
		// g[i].back() = second child
		// if childs' are equal, skip
		if(p[x] == p[g[i].back()]) continue;
		// merge childs
		merge(x, g[i].back());
	}
	int co = 0;
	FOR(i,1,n) {
		if(!cnt[p[i]]) cnt[p[i]] = ++co;
		cout << cnt[p[i]] << '\n';
	}

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACHy
	* template by bqi343
*/