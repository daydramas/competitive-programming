/**
 * CF Spreadsheets
 * https://codeforces.com/contest/1/problem/B
 * Created on 2021-02-17
 */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

bool digit(char c) {
	return (c >= '0' && c <= '9');
}
string tobase26(int n) {
	string ret = "";
	while (1) {
		if (n % 26) ret += ('A' + (n % 26) - 1);
		else ret += ('A' + (26) - 1);
		if (n % 26) n = n / 26;
		else n = n / 26 - 1;
		if (n == 0) break;
	}
	reverse(begin(ret), end(ret));
	return ret;
}
int tobase10(string s) {
	int ret = 0, pow = 1;
	reverse(begin(s), end(s));
	for (char c : s) {
		ret += pow * (c - 'A' + 1);
		pow *= 26;
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	static int t;
	int _, __;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		if (sscanf(s.c_str(), "R%dC%d", &_, &__) == 2) {
			int i = 1, a = 0, b = 0;
			while (digit(s[i]))
				a = 10 * a + (s[i++] - '0');
			++i;
			while (i < s.length())
				b = 10 * b + (s[i++] - '0');
			cout << tobase26(b) << a << '\n';
		} else {
			int i = 0, b = 0;
			string a = "";
			while (!digit(s[i]))
				a += s[i++];
			while (i < s.length())
				b = 10 * b + (s[i++] - '0');
			cout << 'R' << b << 'C' << tobase10(a) << '\n';
		}
	}
}