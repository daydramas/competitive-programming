/**
 * problem-name
 * problem-link
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int d = 9;
		if(n == 1) cout << "9";
		else if (n == 2) cout << "98";
		else if (n == 3) cout << "989";
		else {
			cout << "989";
			for(int i=3; i<n; i++) cout << (i-3)%10;
		}
		cout << '\n';
	}
}