#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int binpow(ll a, ll p, ll mod) {
	if (p == 0) return 1;
	ll b = binpow(a * a % mod, p / 2,mod);
	if (p & 1) b = b * a % mod;
	return b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		ll a, b, c; cin >> a >> b >> c;
		cout << binpow(a,binpow(b,c,MOD-1),MOD) << '\n';
	}
}