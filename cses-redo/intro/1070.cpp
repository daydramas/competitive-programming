/**
 * CSES Permutations
 * https://cses.fi/problemset/task/1070
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n; 

	cin >> n;

	if(n == 1) return cout << 1 << '\n', 0; 
	if(n <= 3) return cout << "NO SOLUTION" << '\n', 0;
	for(int i=2; i<=n; i+=2) cout << i << ' ';
	for(int i=1; i<=n; i+=2) cout << i << ' ';
	cout << '\n';
}