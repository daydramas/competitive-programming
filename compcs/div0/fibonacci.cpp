/**
 * fibonacci
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5
typedef long long ll;

ll dp[100];

ll fib(int x) {
	if(x <= 2) return 1;
	if(dp[x]) return dp[x];
	return dp[x] = (fib(x-1) + fib(x-2));
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("fibonacci.in", "r", stdin);
	freopen("fibonacci.out", "w", stdout);

	static int n;
	cin >> n;
	cout << fib(n) << '\n';
}