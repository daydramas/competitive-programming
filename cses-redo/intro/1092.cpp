/**
 * CSES Two Sets
 * https://cses.fi/problemset/task/1092
*/

#include <iostream>
using namespace std;

#define N	1000005

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	static int n;
	static long long sum;
	static int a[N]{0}, b[N]{0};

	cin >> n;
	sum = 1LL * n * (n + 1) / 2;
	
	if(sum & 1) return cout << "NO" << '\n', 0;
	cout << "YES" << '\n';
	sum >>= 1;
	for(int i=n; i>=1; i--) {
		if(sum >= i) a[++a[0]] = i, sum -= i;
		else b[++b[0]] = i;
	}
	cout << a[0] << '\n';
	for(int i=1; i<=a[0]; i++) cout << a[i] << ' ';
	cout << '\n' << b[0] << '\n';
	for(int i=1; i<=b[0]; i++) cout << b[i] << ' ';
	cout << '\n';
}