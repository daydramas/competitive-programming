#include <bits/stdc++.h>
using namespace std;

// structures/defines
const int maxn = 100005;

// global variables
int N;
int hair[maxn];
long long bit[maxn];
long long ans[maxn];
vector<int> where[maxn];

//functions
void update(int i, int val) {
	for (; i <= N; i += i & (-i)) {
		bit[i] += val;
	}
}
long long sum(int i) {
	long long sum = 0;
	for (; i > 0; i -= i & (-i))
		sum += bit[i];
	return sum;
}
int main() {
	// local variables

	// fstream
	ifstream fin("haircut.in");
	ofstream fout("haircut.out");

	// input
	fin >> N;
	for (int i = 1; i <= N; i++) {
		fin >> hair[i];
		int n = hair[i];
		if (n == N)
			n--;
		where[n].push_back(i);
	}

	// main

	for (int m = N - 1; m > N - 2; m--) {
		int nhair[maxn];
		for (int i = 1; i <= N; i++) {
			nhair[i] = min(hair[i], m);
			bit[i] = 0;
		}
		long long tans = 0;
		for (int i = N; i >= 1; i--) {
			long long q = sum(nhair[i]);
			tans += q;
			update(nhair[i] + 1, 1);

		}
		ans[m] = tans;
	}
	for (int i = 1; i <= N; i++)
		bit[i] = 0;
	for (int m = N - 2; m >= 0; m--) {
		for (int w : where[m + 1]) {
			update(w, 1);
		}
		int diff = 0;
		for (int W : where[m]) {
			int val = sum(W);
			diff -= val;
		}
		ans[m] = ans[m + 1] + diff;

	}
// output
	for (int i = 0; i < N; i++) fout << ans[i] << endl;
	return 0;
}
