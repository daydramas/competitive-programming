/**
 * CSES Weird Algorithm
 * https://cses.fi/problemset/task/1068
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static long long n; 
	
	cin >> n;
	while(n != 1) {
		cout << n << ' ';
		n = (n & 1 ? n * 3 + 1 : n >> 1);
	}
	cout << 1 << '\n';
}