#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	static int comp[4*10000];
	vector<int> primes;
	for(int i=2; i<4*10000; i++) {
		if(!comp[i]) {
			primes.push_back(i);
			for(int j=i; j<4*10000; j+=i) {
				comp[j] = 1;
			}
		}
	}
	int t; cin >> t;
	while(t--) {
		int d; cin >> d;
		int fst = *lower_bound(all(primes), 1+d);
		int snd = *lower_bound(all(primes), fst+d);
		cout << fst*snd << '\n';
	}

}