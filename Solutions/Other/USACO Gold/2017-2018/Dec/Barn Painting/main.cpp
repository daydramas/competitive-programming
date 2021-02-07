/*
 ID: dongliu3
 TASK: barnpainting
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

/* Defines */

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) 
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) 
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) 
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define dbg(x) cout <<#x<<": "<<x<<"\n";
#define dbg2(x,y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n";

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

#define INF 1000000000
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define PI acos(-1.0)

/* Typdefs */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

/* IO */

namespace IO {
	ifstream fin;
	ofstream fout;

	/* FILE SETUP */
	void setIO(const string &PROB = "") { // Input/Output Setup
		ios::sync_with_stdio(false);
		fin.tie(nullptr);
		fin.open(PROB + ".in");
		fout.open(PROB + ".out");
	}
	void setTC(const string& PROB = "", const string& TC = "") { // Test Case Setup
		ios::sync_with_stdio(false);
		fin.tie(nullptr);
		fin.open(TC + ".in");
		fout.open(PROB + ".out");
	}

	/* INPUT */
	template<class T> void cr(T& obj) { T a; cin>>a; obj=a; }; // console read
	template<class T, class... Ts> void cr(T& t, Ts&... ts) { cr(t); cr(ts...); } // console read
	template<class T> void cra(int n, T& arr, int s1=0) { for(int i=s1; i<(n+s1); ++i) cr(arr[i]); } // console read array
	template<class T> void fr(T& obj) { T a; fin>>a; obj=a; }; // file read
	template<class T, class... Ts> void fr(T& t, Ts&... ts) { fr(t); fr(ts...); } // file read
	template<class T> void fra(int n, T& arr, int s1=0) { for(int i=s1; i<(n+s1); ++i) fr(arr[i]); } // file read array

	/* OUTPUT */ 
	template<class T> void cw(T& obj) { cout << obj;} // console write
	template<class T, class... Ts> void cw(T& t, Ts&... ts) { cw(t); cw(ts...); } // console write
	template<class... Ts> void cwl(Ts&... ts) { cw(ts...); cw("\n"); } // conosle write line
	template<class T> void fw(T& obj) { fout << obj;} // file write
	template<class T, class... Ts> void fw(T& t, Ts&... ts) { fw(t); fw(ts...); } // file write
	template<class... Ts> void fwl(Ts&... ts) { fw(ts...); fw("\n"); } // file write line
}
using namespace IO;

/* ============================ */

const ll MOD = 1e9 + 7;

ll dp[100005][5];
int color[100005]; 
vi adj[100005];

ll solve(int s, int sC, int p=-1, int pC=-1) {
	if (color[s]!=-1 && sC!=color[s]) return 0;
	if (sC == pC) return 0;
	if (dp[s][sC]!=-1) return dp[s][sC];
	dp[s][sC] = 1;
	for (int d : adj[s]) {
		if (p == d) continue;
		ll cnt = 0;
		for1(c, 3) {
			cnt += solve(d, c, s, sC);
			cnt %= MOD;
		}
		dp[s][sC] *= cnt;
		dp[s][sC] %= MOD;
	}
	return dp[s][sC];
}
int main() {

	// cout <<"\n+------ Starting\n"; clock_t startT = clock(); 
	setIO("barnpainting"); // setTC("barnpainting", "XX");

	int n, k;
	fr(n, k);

	memset(color, -1, sizeof(color));
	memset(dp, -1, sizeof(dp));
	for0(i, n-1) {
		int a, b; fr(a, b);
		adj[a].pb(b), adj[b].pb(a);
	}	
	for0(i, k) {
		int a, c; fr(a, c);
		color[a] = c;
	}

	fout << (solve(1, 1)+solve(1, 2)+solve(1, 3)) % MOD << "\n";
	// cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
	return 0;
}
 