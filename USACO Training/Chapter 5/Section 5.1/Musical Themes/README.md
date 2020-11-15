```cpp
/*
 ID: dongliu3
 TASK: theme
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int n[5001];
map<int, int> S[5001];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("theme.in");
	ofstream fout("theme.out");

	// input
	fin >> N;
	for (int i=0; i<N; i++) fin >> n[i];

	// main
	int ans = -1;
	for (int i = 5; i < N; i++) {
		int a = i, b = 1;
		for (int j = i + 1; j < N; j++) {
			if (n[j] - n[j-i] == n[j-1] - n[j-i-1] && j-i<a) {
				b++;
				if (b > ans) ans = b;
			} else {
				a = j;
				b = 1;
			}
		}
	}

	// output

	if (ans < 5) ans = 0;
	fout << ans << endl;
	return 0;
}
```