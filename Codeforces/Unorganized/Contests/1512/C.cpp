#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int tc; cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		string s; cin >> s;
		int n = s.length();
		string t = s;
		reverse(begin(t), end(t));
		for (int i = 0; i < n; ++i)
			if (s[i] == '0') a--;
			else if (s[i] == '1') b--;
		bool ok = true;
		if (a < 0 || b < 0) {
			ok = false;
		}
		vector<int> p;
		for (int i = 0; i * 2 < n; ++i)	{
			if (s[i] != '?' && t[i] != '?')
				if (s[i] != t[i])
					ok = false;
			if (s[i] == '?' && t[i] != '?')
				p.push_back(i);
			if (s[i] != '?' && t[i] == '?')
				p.push_back(i);
		}
		for (int i : p) {
			if (s[i] == '?') {
				s[i] = t[i];
				if (t[i] == '0') a--;
				else b--;
			} else {
				s[n - i - 1] = s[i];
				if (s[i] == '0') a--;
				else b--;
			}
		}
		if (n & 1) {
			if (s[n / 2] == '?')
				if (a & 1)
					s[n / 2] = '0', a--;
				else
					s[n / 2] = '1', b--;
		}
		if (a < 0 || b < 0)
			ok = false;
		if (a % 2) 
			ok = false;
		if (b % 2)
			ok = false;
		if (ok) {
			for (int i = 0; i < n; ++i)
				if (s[i] == '?')
					if (a > 0)
						a -= 2, s[i] = s[n - i - 1]= '0';
					else
						b -= 2, s[i] = s[n - i - 1]= '1';
			cout << s << '\n';
		} else {
			cout << "-1\n";
		}
	}
}