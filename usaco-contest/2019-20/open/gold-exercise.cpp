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


int main() {
	IO("exercise");

	int n; ll m; 
	cin >> n >> m;

	bool comp[n+1]{}; vi primes;
	FOR(i,2,n) if(!comp[i]) {
		primes.PB(i);
		FOR(k,1,n/i) comp[i*k] = 1;
	}

	ll dp[SZ(primes)+1][n+1]{};
	F0R(i,n+1) dp[0][i] = 1;
	FOR(i,1,SZ(primes)) {
		F0R(j,n+1) {
			dp[i][j] = dp[i-1][j];
			int pp = primes[i-1];
			while(pp <= j) {
				dp[i][j] = (dp[i][j] + (pp * dp[i-1][j-pp]) % m) % m;
				pp *= primes[i-1];
			}
		}
	}
	cout << dp[SZ(primes)][n] << '\n';
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACHy
	* template by bqi343
*/