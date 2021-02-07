/**
 * evensteven
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	freopen("evensteven.in", "r", stdin);
	freopen("evensteven.out", "w", stdout);

	static int n;
	cin >> n;
	for(int i=2; i<=n; i+=2) {
		cout << i << '\n';
	}
}