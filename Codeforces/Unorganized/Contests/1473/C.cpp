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

	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		int d = n-k;
		FOR(i,1,k) {
			if(i < k-d) {
				cout << i << ' ';
			} else {
				cout << k+k-d-i << ' ';
			}
		}
		cout << '\n';
	}

}