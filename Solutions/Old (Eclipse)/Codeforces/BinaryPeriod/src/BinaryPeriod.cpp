#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define ll long long

// global variables

// functions
char getop(char ch) {
	if (ch == '1')
		return '0';
	return '1';
}
void solve() {
	string str;
	cin >> str;
	bool same = true;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1])
			same = false;
	}
	if (same) {
		cout << str << endl;
	} else {
		string ans = "";
		ans += str[0];
		for (int i = 1; i < str.size(); i++) {
			if (str[i] == str[i - 1]) {
				ans += getop(str[i]);
			}
			ans += str[i];
		}
		cout << ans << endl;
	}
}
int main() {
	// local variables

	// input
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
	// main

	// output

	return 0;
}
