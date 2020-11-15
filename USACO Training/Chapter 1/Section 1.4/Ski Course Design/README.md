```cpp
/*
 ID: dongliu3
 TASK: skidesign
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int height[1010];
// functions
int sq(int a) {
	return a*a;
}
int main() {
	// local variables

	// fstream
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) {
		fin >> height[i];
	}
	// main
	int cnt = 1000000000;
	for (int i=0; i<=(100-17); i++) {
		int tcnt = 0;
		for (int j=1; j<=N; j++) {
			if (height[j] < i) {
				tcnt += sq(i-height[j]);
			} else if (height[j]>i+17) {
				tcnt += sq(height[j]-(i+17));
			}
		}
		cnt = min(cnt, tcnt);
	}
	// output
	fout << cnt << endl;
	return 0;
}
```