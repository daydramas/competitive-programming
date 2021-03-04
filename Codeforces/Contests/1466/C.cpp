#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int b[100000] = {0};
		int cnt = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == s[i - 1] && !b[i - 1])
				b[i] = 1;
			if (s[i] == s[i - 2] && !b[i - 2]) 
				b[i] = 1;
			cnt += b[i];
		}
		cout << cnt << '\n';
	}	
}