/**
 * CSES Palindrome Reorder
 * https://cses.fi/problemset/task/1755
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int a[26], sp;
	static string s, re;

	cin >> s;
	for (char c : s)
		a[c - 'A']++;
	for (int i = 0; i < 26; i++) {
		if (a[i] & 1) {
			if (sp)
				return cout << "NO SOLUTION" << '\n', 0;
			else
				sp = i + 1;
		}
		for (int j = 0; j < a[i] / 2; j++)
			re += ('A' + i);
	}
	cout << re;
	if (sp)
		cout << char(sp + 'A' - 1);
	reverse(re.begin(), re.end());
	cout << re << '\n';
}