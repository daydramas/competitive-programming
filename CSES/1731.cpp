#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int M = 100000;
const int K = 26;
const int MOD = 1000000007;

struct T {
	T *c[K];
	bool x;
	T() : x(0) {}
} *root;

string s, t;
int n, m, dp[N];

T* node() {
	T* kk = new T;
	kk->x = false;
	for (int k = 0; k < K; ++k)
		kk->c[k] = NULL;
	return kk;
}

void insert(const string& t) {
	T *tt = root; int i;
	for (const char &c : t) {
		i = c - 'a';
		if (tt->c[i] == NULL)
			tt->c[i] = node();
		tt = tt->c[i];
	}
	tt->x = true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> s;
	int n = s.length();

	cin >> m;
	root = node();
	while (m--) {
		cin >> t;
		insert(t);
	}

	dp[0] = 1;
	T *tt;
	for (int i = 0; i < n; ++i) {
		tt = root;
		for (int j = i + 1, k; j <= n; ++j) {
			k = s[j - 1] - 'a';
			if (tt->c[k] == NULL)
				break;
			tt = tt->c[k];
			if (tt->x)
				dp[j] = (dp[j] + dp[i]) % MOD;
		}
	}
	cout << dp[n] << '\n';

}