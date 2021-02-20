/**
 * CF Spreadsheets
 * https://codeforces.com/contest/1/problem/B
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

bool digit(char c) {
	return (c >= '0' && c <= '9');
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int t; string s;
	cin >> t;
	while (t--) {
		cin >> s;
		if (s[0] == 'R' && digit(s[1])) {
			int i = 1, a = 0, b = 0;
			while(digit(s[i])) {
				a = 10 * a + (s[i++] - '0');
			} ++i;
			while(i < s.length()) {
				b = 10 * b + (s[i++] - '0');
			}
			cout << "A = " << a << " | B = " << b << '\n';
		} else {
			
		}
	}
}