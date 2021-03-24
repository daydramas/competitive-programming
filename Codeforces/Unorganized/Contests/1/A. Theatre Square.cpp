#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	long long n, m, a;

	cin >> n >> m >> a;
	
	auto divide = [](long long a, long long b) {
		return (a / b) + (a % b ? 1 : 0);
	};

	cout << divide(n, a) * divide(m, a) << '\n';
}