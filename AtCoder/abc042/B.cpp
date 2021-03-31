#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, l;
string s[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s, s + n);
	for (int i = 0; i < n; ++i)
		printf("%s", s[i].c_str());
	printf("\n");
}