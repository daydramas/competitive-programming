/**
 * CSES Gray Code
 * https://cses.fi/problemset/task/2205
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, v;
	cin >> n;

	for(int i=0; i<(1<<n); i++) {
		v = i ^ (i>>1);
		for(int j=n-1; j>=0; j--) {
			cout << bool(v & (1<<j));
		}
		cout << '\n';
	}
}