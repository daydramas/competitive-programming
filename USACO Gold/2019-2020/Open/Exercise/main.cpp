/*
 ID: dongliu3
 TASK: exercise
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
#define DBG(x) cout <<#x<<": "<<x<<endl;
#define DBG2(x,y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

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

ifstream fin;
ofstream fout;

void setIO(const string &PROB = "") {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	if (PROB.length() != 0) {
		ifstream infile(PROB + ".in");
		if (infile.good()) {
			fin.open(PROB + ".in");
			fout.open(PROB + ".out");
		}
	}
}

/* ============================ */

ll n, m;
ll cnt[1505][10005];
vi primes; bool composite[10005];

int main() {
    setIO("exercise");
	
	fin >> n >> m;

	// Sieve of Eratosthenes (to calculate primes)
	memset(composite, false, sizeof(composite));
	for1(i, n) if (i!=1 && !composite[i]) {
		primes.pb(i);
		for(int j=i*i; j<=n; j+=i) {
			composite[j] = true;
		}
	}
	// cnt[i][j] = sum of all possible ones usiang primes from (1-i) and space 
	for(int i=0; i<=n; i++) cnt[0][i]=1;
	for1(i, primes.size()) for(int j=0; j<=n; j++) {
		cnt[i][j] = cnt[i-1][j];
		int d = primes[i-1];
		while (d <= j) {
			cnt[i][j] = ( cnt[i][j] + ( d * cnt[i-1][j-d] % m )  ) % m;
			d *= primes[i-1];
		}
	}

	fout << cnt[sz(primes)][n] << "\n";
	return 0;
}
