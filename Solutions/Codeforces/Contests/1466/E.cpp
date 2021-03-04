#include <iostream>
using namespace std;

const int mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n;
		long long a[500000];
		long long b[60] = {0};
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < 60; ++j) {
				if ((1LL << j) & a[i])
					b[j]++;
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			long long _and = 0, _or = 0;
			for (int j = 0; j < 60; ++j) {
				if ((1LL << j) & a[i]) {
					_and = (_and + (1LL << j) % mod * b[j] % mod) % mod;
					_or = (_or + (1LL << j) % mod * n % mod) % mod;
				} else {
					_or = (_or + (1LL << j) % mod * b[j] % mod) % mod;
				}
			}
			ans = (ans + _and * _or % mod) % mod;
		}
		cout << ans << '\n';
	}	
}