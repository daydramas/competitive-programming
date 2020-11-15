```cpp
/*
 ID: dongliu3
 TASK: combo
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int fj[3], mt[3];

// functions
bool open(int combo[3]) {
	bool FJ = true, MT = true;
	for (int i=0; i<3; i++) {
		FJ &= (abs(fj[i]-combo[i])<=2) || (abs(fj[i]-combo[i])>=N-2);
		MT &= (abs(mt[i]-combo[i])<=2) || (abs(mt[i]-combo[i])>=N-2);
	}
	return (FJ || MT);
}
int main() {
	// local variables

	// fstream
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	// input
	fin >> N;
	for (int i=0; i<3; i++) {
		fin >> fj[i];
	}
	for (int i=0; i<3; i++) {
		fin >> mt[i];
	}
	// main
	int ans = 0;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=1; k<=N; k++) {
				int combo[] = {i, j, k};
				if (open(combo)) {
					ans++;
				}
			}
		}
	}
	// output
	fout << ans << endl;
	return 0;
}
```