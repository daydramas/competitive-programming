/*
 ID: dongliu3
 TASK: buylow
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
struct bignum {
	vector<int> v;
	void add(bignum b) {
		bignum c;
		int s1 = v.size(), s2 = b.v.size();
		int ms = max(s1, s2), carry = 0;
		for (int i=0; i<ms; i++) {
			int a1=0, b1=0;
			if (s1 >= i+1) a1 = v[i];
			if (s2 >= i+1) b1 = b.v[i];
			int sm = a1+b1+carry;
			c.v.push_back(sm%10);
			carry = (sm/10);
		}
		if (carry) c.v.push_back(carry);
		v = c.v;
	}
};
// global variables
int N; int P[5001];
int dp[5001]; bignum dp2[5001];
int ans1; bignum ans2;

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("buylow.in");
	ofstream fout("buylow.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) fin >> P[i];
	for (int i=1; i<=N; i++) dp[i] = 1;

	// main
	// calculate maximum length
	dp[0] = 0, P[0] = 1000000000, ans1 = -1;
	for (int i=1; i<=N; i++) {
		for (int j=0; j<i; j++) if (P[j] > P[i]) {
			dp[i] = max(dp[i], dp[j]+1);
			ans1 = max(ans1, dp[i]);
		}
	}
	// calculate number of max length solutions
	for (int i=1; i<=N; i++) {
		if (dp[i] == 1) {
			dp2[i].v.push_back(1);
			continue;
		}
		dp2[i].v.push_back(0);
		int back1 = dp[i]-1, last1 = -1;
		for (int j=i-1; j>=0; j--) if (P[j] > P[i]) {
			if (back1 == dp[j] && last1 != P[j]) {
				dp2[i].add(dp2[j]);
				last1 = P[j];
			}
		}
	}

	// output
	ans2.v.push_back(0);
	int last1 = -1;
	for (int i=N; i>=1; i--) if (dp[i] == ans1 && last1 != P[i]) {
		ans2.add(dp2[i]);
		last1 = P[i];
	}
	fout << ans1 << " ";
	for (int i=ans2.v.size()-1; i>=0; i--) fout << ans2.v[i];
	fout << endl;
	return 0;
}