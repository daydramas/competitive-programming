/**
 * sumall
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	static int n;
	long long x, sum;

	freopen("sumall.in", "r", stdin);
	freopen("sumall.out", "w", stdout);

	cin >> n;
	sum = 0;
	while(n--) {
		cin >> x;
		sum += x;
	}
	cout << sum << '\n';
}