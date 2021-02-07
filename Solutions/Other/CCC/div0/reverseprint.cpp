/**
 * reverseprint
*/

#include <iostream>
using namespace std;

const int N = 1e3;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("reverseprint.in", "r", stdin);
	freopen("reverseprint.out", "w", stdout);

	static int n, a[N];
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=n-1; i>=0; i--) {
		cout << a[i] << '\n';
	}
}