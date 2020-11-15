```cpp
/*
 ID: dongliu3
 TASK: lgame
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
string N;
set<string> word;
int dp[10]; string dps[10];
int pnt[30] = { 2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4,
		6, 6, 7, 5, 7};
// functions
int COUNT (string str) {
	int sum = 0;
	for (char ch : str) if (ch != ' ') sum += pnt[ch-'a'];
	return sum;
}
int main() {
	// local variables

	// fstream
	ifstream fin("lgame.in");
	ifstream fin2("lgame.dict");
	ofstream fout("lgame.out");

	// input
	fin >> N; string str;
	while(fin2 >> str) {
		if (str == ".") break;
		else word.insert(str);
	}

	// main
	int ans = -1; vector<string> ans2;
	// sort N (for some reason when you don't sort, next_permutation does not work
	sort(N.begin(), N.end());
	do {
		// compute dp for string N
		int M = N.size(); string N2 = " "+N;
		fill(dp, dp+M+1, 0); dps[0] = "";
		for (int i=1; i<=M; i++) for (int j=0; j<i; j++) {
			string ns = N2.substr(j+1, i-j);
			if (word.find(ns) != word.end()) {
				int no = dp[j]+COUNT(ns);
				if (no > dp[i]) {
					dp[i] = no;
					dps[i] = dps[j]+" "+ns;
				}
			}
		}
		// update ans and ans2
		int mx = -1;
		for (int i=1; i<=M; i++) {
			mx = max(mx, dp[i]);
			if (dp[i]>ans) {
				ans = dp[i];
				ans2.clear();
				ans2.push_back(dps[i]);
			} else if (dp[i] == ans && COUNT(dps[i]) == ans) {
				ans2.push_back(dps[i]);
			}
		}
	} while (next_permutation(N.begin(), N.end()));

	// output
	set<string> ans3;
	for (string s : ans2) {
		// convert into separate strings
		vector<string> total;
		string curr = "";
		for (char ch : s) {
			if (ch == ' ') {
				total.push_back(curr);
				curr = "";
			} else curr += string(1, ch);
		}
		total.push_back(curr);
		sort(total.begin(), total.end());

		// convert back into strings
		string total2 = "";
		for (string str : total) {
			total2 = total2 + " " + str;
		}
		ans3.insert(total2);
	}
	fout << ans << endl;
	for (string s : ans3){
		// remove the spaces
		s.erase(s.begin(), s.begin()+2);
		// output
		fout << s << endl;
	}
	return 0;
}
```