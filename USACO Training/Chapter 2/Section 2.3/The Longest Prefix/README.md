# The Longest Prefix
```cpp
/*
 ID: dongliu3
 TASK: prefix
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
string P[200];
bool dp[200001];
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	// input
	string in; int index = 0;
	fin >> in;
	while(in != ".") {
		P[index++] = in;
		fin >> in;
	}
	string target; target = "";
	while(fin.good()) {
		string n; fin >> n;
		target += n;
	}
	fill(dp, dp+200001, false);
	// main
	dp[0] = true;
	for (int i=0; i<=target.size(); i++) {
		for (int j=0; j<index; j++) {
			if (i+P[j].size() > target.size()) continue;
			string temp = target.substr(i, P[j].size());
			if (temp == P[j]) {
				dp[i+P[j].size()] |= dp[i];
			}
		}
	}
	// output
	int cnt = 0;
	for (int i=0;i<=target.size(); i++) {
		if (dp[i]) cnt = max(cnt, i);
	}
	fout << cnt << endl;
	return 0;
}
```