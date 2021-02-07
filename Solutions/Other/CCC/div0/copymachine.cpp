/**
 * copymachine
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("copymachine.in", "r", stdin);
	freopen("copymachine.out", "w", stdout);

	static int n, x;
	
	cin >> n;
	while(n--) {
		cin >> x;
		cout << x << '\n';
	}
}