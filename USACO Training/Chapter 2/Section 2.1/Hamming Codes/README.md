```cpp
/*
 ID: dongliu3
 TASK: hamming
 LANG: C++
 */

#include <bits/stdc++.h>
#include <bitset>
using namespace std;

// structures/defines

// global variables
int N, B, D;
vector<int> cnt;

// functions
int check1(int a, int b) {
	bitset<8> b1(a^b);
	return b1.count();
}
int main() {
	// local variables

	// fstream
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	// input
	fin >> N >> B >> D;

	// main
	for (int i=0; i<=(1<<B); i++) {
		bool yes = true;
		for (int j : cnt) {
			yes &= (check1(i, j) >= D);
		}
		if (yes) cnt.push_back(i);
		if (cnt.size() == N) break;
	}
	// output
	for (int i=0; i<N; i++) {
		fout << cnt[i];
		if ((i+1)%10 == 0 || i+1==N) {
			fout << endl;
		} else fout << " ";
	}
	return 0;
}
```