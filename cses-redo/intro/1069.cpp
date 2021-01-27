/**
 * CSES Repetitions
 * https://cses.fi/problemset/task/1069
*/

#include <iostream>
#include <string>
using namespace std;

inline int MAX(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	static int ans, cur;

	cin >> s;
	ans = cur = 1;
	for(int i=1; i<s.length(); i++) {
		if(s[i] == s[i-1]) ans = MAX(ans, ++cur);
		else cur = 1;
	}
	cout << ans << '\n';
}