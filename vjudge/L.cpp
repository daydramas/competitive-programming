/**
 * L - Fire
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define N	110
#define M	8021

int n, t[N], d[N], p[N], o[N];
long long dp[N][M], pre[N][M];

bool compare(int i, int j) {
	if(d[i] == d[j]) {
		return t[i] < t[j];
	} else {
		return d[i] < d[j];
	}
}

// template <class T> bool ckmax(T& a, const T& b) { 
// 	return b > a ? a = b, 1 : 0; 
// }

int main() {

	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> t[i] >> d[i] >> p[i];
		o[i] = i;
	}
	sort(o+1, o+n+1, compare);
	o[0] = 0;
	for(int i=1; i<=n; i++)
	for(int j=0; j<M; j++) {
		pre[i][j] = 0;
		dp[i][j] = 0;
	}
	dp[0][0] = 0;
	// for(int i=1; i<=n; i++) cout <<"o["<<i<<"] = " << o[i] << '\n';
	for(int i=1; i<=n; i++) {
		int I = o[i];
		for(int k=0; k<i; k++) {
			int J = o[k];
			for(int j=0; j<M; j++) {
				if(j + t[I] < d[I]) {
					if(dp[J][j] + p[I] > dp[I][j + t[I]]) {
						pre[I][j + t[I]] = J;
						dp[I][j + t[I]] = dp[J][j] + p[I];
					}
				}
			}
		}
	}
	long long ans = 0, ansi, ansk;
	for(int i=1; i<=n; i++)
	for(int j=0; j<M; j++) {
		if(dp[i][j] > ans) {
			ans = dp[i][j];
			ansi = i;
			ansk = j;
		}
	}
	// cout << "dp[9][32] = "<<dp[9][32]<<'\n';
	cout << ans << '\n';
	vector<int> ansv;
	while(ansi > 0 && ansk >= 0 && ansk < M) {
		ansv.push_back(ansi);
		int temp = ansi;
		ansi = pre[ansi][ansk];
		ansk = ansk - t[temp];
	}
	reverse(begin(ansv), end(ansv));
	cout << ansv.size() << '\n';
	for(int x : ansv) cout << x << ' ';
	cout << '\n';
}