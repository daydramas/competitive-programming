#include <bits/stdc++.h>
using namespace std;

long double n;

int main() {
	cin >> n;
	long double l = 0.00000001, hi = n;
	while(l + 0.00000001 < hi) {
		// cout << l << ' ' << hi << '\n';
		long double m = (l + hi) / 2;
		long double v = m * m * m + (m * 3) * (m * 3) * (m * 3) + (m * 5) * (m * 5) * (m * 5);
		// cout << "v = " << v << '\n';
		if(v > n) hi = m;
		else l = m;
	}
	cout << fixed << setprecision(15) << l << '\n';
}