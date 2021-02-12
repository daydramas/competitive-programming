/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-11
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define F           first
#define S           second
#define PB          push_back
#define ALL(x)      begin(x), end(x)
#define SZ(x)       int((x).size())
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define F0R(i,x)    FOR(i,0,(x)-1)
#define ROF(i,a,b)  for(int i=(b); i>=(a); --i)
#define R0F(i,x)    ROF(i,0,(x)-1)
#define REP(x)      F0R(_,x)
#define EACH(a,x)   for(auto& a: x)

template<class T> bool ckmin(T& a, const T& b) {
	return (a > b ? a = b, 1 : 0); }
template<class T> bool ckmax(T& a, const T& b) {
	return (a < b ? a = b, 1 : 0); }

inline namespace IO {
	template<class T> void read(vector<T>& x);
	template<class T, class U> void read(pair<T, U>& x);
	template<class T> void read(T& x) { cin >> x; }
	template<class T, class... U> void read(T& x, U&... y) { read(x); read(y...); }
	template<class T> void read(vector<T>& x) { EACH(a, x) read(a); }
	template<class T, class U> void read(pair<T, U>& x) { read(x.F, x.S); }
	template<class T> void write(const vector<T>& x);
	template<class T, class U> void write(const pair<T, U>& x);
	template<class T> void write(const T& x) { cout << x; }
	template<class T, class... U> void write(const T& x, const U&... y) { write(x); write(y...); }
	template<class T> void write(const vector<T>& x) { bool f=1; EACH(a, x) { if(!f) write(" "); write(a); f=0; } };
	template<class T, class U> void write(const pair<T, U>& x) { write(x.F, " ", x.S); }
	template<class T> void print(const T& x) { write(x, "\n"); }
	template<class T, class... U> void print(const T& x, const U&... y) { write(x, " "); print(y...); }
	template<class T> void pdebug(const T& x) { write(x, "]\n"); cout.flush(); }
	template<class T, class... U> void pdebug(const T& x, const U&... y) { write(x, ", "); pdebug(y...); }
	#define debug(...) cout << "LINE(" << __LINE__ << ") => [" << #__VA_ARGS__ << "] => " << "]: [", pdebug(__VA_ARGS__)
};

using pd = pair<long double, long double>;
#define sq(x) (x) * (x)
long double dist(pd a, pd b) {
	return sqrt(sq(a.F-b.F) + sq(a.S-b.S));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	pd alice, bob; 
	read(alice, bob);
	int n; read(n);
	REP(n) {
		pd eve; read(eve);
		if(abs(dist(alice, bob)-dist(alice, eve)-dist(eve, bob)) <= 0.000001) cout << "Yes\n";
		else cout << "No\n";
	}

}