# Milk Measuring
```cpp
/*
 ID: dongliu3
 TASK: milk4
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int Q, P, p[101];
bool used[101];
int ans = 102;
string anss = "";
ofstream fout("milk4.out");
// functions
bool ok () {
	bool dp[Q+5];
	for (int i=0; i<=Q; i++) dp[i] = false;
	dp[0] = true;
	for (int i=1; i<=P; i++) {
		if (used[i]) {

			for (int j=0; j+p[i]<=Q; j++) {
				dp[j+p[i]] |= dp[j];
//				if (dp[j]) cout << "ok: "<<j<<endl;
			}
		}
	}
	return dp[Q];
}
void dfs(int i, int nuse, int n) {
	if (ans != 102) return;
	if (nuse == 0) {
		if (ok()) {
			//compare with answer
			if (ans==102) {
				string out = "";
//				fout << n <<" ";
				out += to_string(n);
				for (int j=1; j<=P; j++) {
					if (used[j]) out += " "+to_string(p[j]);
				}
				fout << out << endl;
				ans = -1;
				return;

			}
		}
		return;
	}
	if (i > P) return;
		used[i] = true;
		dfs(i+1, nuse-1, n+1);
		used[i] = false;
		dfs(i+1, nuse, n);

}
int main() {
	// local variables

	// fstream
	ifstream fin("milk4.in");

	// input
	fin >> Q >> P;
	for (int i=1; i<=P; i++) {
		fin >> p[i];
		used[i] = false;
	}
	sort(p+1, p+P+1);
//	used[1] = used[3] = true;
//	cout << ok() << endl;
	// main
	for (int i=1; i<=P; i++) {
		dfs(1, i, 0);
		if (ans != 102) break;
	}
//
	// output
//	cout << ans <<anss<<endl;

	return 0;
}

```