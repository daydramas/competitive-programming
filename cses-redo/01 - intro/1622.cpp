/**
 * CSES Creating Strings
 * https://cses.fi/problemset/task/1622/
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define N	40320

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n = 0;
	static string s, a[N];

	cin >> s;
	sort(s.begin(), s.end());
	do {
		a[n++] = s;
	} while(next_permutation(s.begin(), s.end()));
	
	cout << n << '\n';
	for(int i=0; i<n; i++) {
		cout << a[i] << '\n';
	}
}