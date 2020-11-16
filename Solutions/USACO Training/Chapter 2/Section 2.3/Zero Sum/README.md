# Zero Sum
```cpp
  
/*
 ID: dongliu3
 TASK: zerosum
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
vector<string> ans;
// functions
bool operation(char a) {
	return a == '+' || a == '-';
}
void check(string a) {
	int temp = 0;
	int index1 = 0;
	char O = '+';
	while (index1 < a.size()) {
		string num = "";
		while (index1 < a.size()) {
			num += a[index1];
			index1++;
			if (operation(a[index1]))
				break;
			index1++;
		}
		if (O == '+') {
			temp += stoi(num);
		} else {
			temp -= stoi(num);
		}
		while (index1 < a.size() && !operation(a[index1]))
			index1++;
		O = a[index1];
		index1++;

	}
	if (temp == 0) {
		ans.push_back(a);
	}
}
void dfs(int index, string curr) {
	if (index == N) {
		check(curr);
		return;
	}
	dfs(index + 1, curr + "+" + to_string(index + 1));
	dfs(index + 1, curr + "-" + to_string(index + 1));
	dfs(index + 1, curr + " " + to_string(index + 1));
}
int main() {
	// local variables

	// fstream
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");

	// input
	fin >> N;

	// main
	dfs(1, "1");

	// output
	sort(ans.begin(), ans.end());
	for (string str : ans ) fout << str << endl;
	return 0;
}
```