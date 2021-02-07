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

const int maxn = 1e3+5;
const int mod = 1e9+7;

struct Edge {
	int b, c, d;
};

int n, m, ways[maxn], w2[2*maxn], dist[maxn], res[2*maxn], w[maxn];

vector<pair<pi,int>> bb[maxn*2];
vector<Edge> adj[maxn]; 

void dijkstra(int src) {
	FOR(i,1,n) ways[i] = 0, dist[i] = 1e9, w[i] = 0;
	F0R(i,m) { w2[i] = 0; bb[i].clear(); } 
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	ways[src] = 1; dist[src] = 0;
	pq.push({0, src});
	while(SZ(pq)) {
		pi f = pq.top(); pq.pop();
		if(f.F > dist[f.S]) continue;
		EACH(e, adj[f.S]) {
			if(dist[e.b] > dist[f.S] + e.c) {
				dist[e.b] = dist[f.S] + e.c;	
				ways[e.b] = ways[f.S];
				// w2[e.d] = ways[f.S];
				pq.push({dist[e.b], e.b});
				bb[e.b].clear();
				bb[e.b].PB({{f.S, ways[f.S]}, e.d}); w[f.S]++;
			} else if(dist[e.b] == dist[f.S] + e.c) {
				ways[e.b] += ways[f.S];
				// w2[e.d] += ways[f.S];
				bb[e.b].PB({{f.S, ways[f.S]},e.d}); w[f.S]++;
				// cout << "w2["<<e.d<<"] += " << ways[f.S]<<'\n';
			} 
		}
	}
	queue<int> q;
	FOR(i,1,n) {
		if(!w[i]) q.push(i);
		// else ways[i] = 0;
	}
	while(SZ(q)) {
		int f = q.front(); q.pop();
		EACH(s, bb[f]) {
			w2[s.S] += w2[f];
			if(!--w[s.F.F]) q.push(s.F.F);
		}
	}
	F0R(i,m) {
		res[i] += w2[i];
		cout << w2[i] << ' ';
	}
	cout << '\n';
}

int main() {
	IO("");

	cin >> n >> m;

	F0R(i,m) {
		int a,b,c; cin >> a >> b >> c;
		adj[a].PB({b,c,i});
		adj[b].PB({a,c,i});
	}
	FOR(i,1,n) dijkstra(i);
	F0R(i,m) cout << res[i] << '\n';

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* template by bqi343
*/