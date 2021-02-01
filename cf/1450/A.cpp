/**
 * frontmatter
*/

#include <bits/stdc++.h>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	int TC, n; cin >> TC;
	while(TC--) {
		string s;
		cin >> n >> s;
		sort(s.begin(), s.end());
		cout << s << '\n';

	}
}