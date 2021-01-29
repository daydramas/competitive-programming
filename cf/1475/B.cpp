/**
 * New Year's Number
 * https://codeforces.com/contest/1475/problem/B
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n;
	static int dp[1000005];

	dp[0] = 1;
	for(int i=0; i<1000000; i++) {
		if(!dp[i]) continue;
		if(i+2020 <= 1000000) dp[i+2020] = 1;
		if(i+2021 <= 1000000) dp[i+2021] = 1;
	}
	cin >> t;
	while(t--) {
		cin >> n;
		cout << (dp[n] ? "YES" : "NO") << '\n';
	}
}