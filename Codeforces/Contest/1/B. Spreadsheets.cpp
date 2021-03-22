#include <bits/stdc++.h>
using namespace std;

string base26(int x) {
	string ret = "";
	while (x) {
		ret += (x % 26 ? 'A' + (x % 26 - 1) : 'Z');
		x = (x % 26 ? x / 26 : x / 26 - 1);
	}
	reverse(begin(ret), end(ret));
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, i, j, k; 
	string s;

	cin >> n;

	while (n--) {
		cin >> s;
		if (sscanf(s.c_str(), "R%dC%d", &i, &j) == 2) {
			cout << base26(j) << i << '\n';
		} else {
			i = 0, j = 0;
			for (k = 0; k < (int)s.size() && isupper(s[k]); ++k)
				i = i * 26 + (s[k] - 'A' + 1);
			for (; k < (int)s.size(); ++k)
				j = j * 10 + (s[k] - '0');
			cout << 'R' << j << 'C' << i << '\n';
		}
	}
}