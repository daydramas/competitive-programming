#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using db = double;
using ld = long double;
using vi = vector<int>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

template<class T> using V = vector<T>;
template<class T, class U> using PR = pair<T, U>;
template<class T> using HEAP = priority_queue<T, V<T>, greater<T>>;

#define MP			make_pair
#define F			first
#define S			second
#define SZ(x)		int((x).size())
#define ALL(x)		(x).begin(), (x).end()
#define RALL(x)		(x).rbegin(), (x).rend()
#define RSZ			resize
#define PF			push_front
#define EB			emplace_back
#define PB			push_back
#define INS			insert
#define FT			front()
#define BK			back()
#define LB			lower_bound
#define UP			upper_bound 
#define FOR(i,x,y)	for(int i=(x); i<=(y); i++)
#define F0R(i,x)	FOR(i, 0, (x)-1)
#define ROF(i,x,y)	for(int i=(y); i>=(x); i--)
#define R0F(i, x)	ROF(i, 0, (x)-1)
#define EACH(i,x)	for(auto& i : (x))

const int MOD = 1e9+7;
const int MX = 1<<18;
const ll INF = 1e18;
const ld PI = acos(-1.0);
const int X[] = {0, 0, -1, 1};
const int Y[] = {1, -1, 0, 0};

template<class T> bool ckmin(T &a, const T &b) {
	return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T &b) {
	return (b > a ? a = b, 1 : 0); }

template<class T, class U> void in(pair<T,U>& p);
template<class T> void in(V<T>& v);
template<class T> void in(T& x) { cin >> x; }
void in(db& d) { str t; in(t); d = stod(t); }
void in(ld& d) { str t; in(t); d = stold(t); }
template<class T, class ...U> void in(T& t, U&... u) { in(t); in(u...); }
template<class T, class U> void in(pair<T,U>& p) { in(p.f,p.s); }
template<class T> void in(V<T>& x) { EACH(a,x) in(a); }

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
template<class T, class U> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}
template<class T> str ts(T v) {
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		EACH(x, v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		EACH(x, v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}

template<class T> void out(T x) { cout << ts(x); }
template<class T, class ...U> void out(const T& t, const U&... u) { out(t); out(u...); }
void outs() { out("\n"); }
template<class T, class ...U> void outs(const T& t, const U&... u) { 
	out(t); if (sizeof...(u)) out(" "); outs(u...); }

void dbg() { cerr << "]" << endl; }
template<class T, class ...U> void dbg(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", "; dbg(u...); }
#ifdef LOCAL
	#define DBG(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg(__VA_ARGS__)
#else
	#define DBG(...) 0
#endif

void FAST() { cin.tie(0)->sync_with_stdio(0); }
void INPUT(str s) { freopen(s.c_str(),"r",stdin); }
void OUTPUT(str s) { freopen(s.c_str(),"w",stdout); }
void IO(str s = "") {
	FAST(); if(!SZ(s)) return;
	INPUT(s+".in"), OUTPUT(s+".out"); 
}



int main() {
	IO("shell");

	int n;
	in(n);
	vi a(n), b(n), g(n);
	F0R(i,n) {
		in(a[i],b[i],g[i]);
		--a[i],--b[i],--g[i];
	}
	int ans=0;
	F0R(i,3) {
		vi l(3);
		int cur=0;
		l[i]=1;
		F0R(j,n) {
			swap(l[a[j]],l[b[j]]);
			cur += l[g[j]];
		}
		ckmax(ans,cur);
	}
	outs(ans);
}