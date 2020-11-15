```cpp
/*
 ID: dongliu3
 TASK: ariprog
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
// global variables
int N, M;
//set<int> S;
vector<pii> cnt;
// functions
int S[125050];
bool ok(int i, int j) {
	int c = 0;
	for (int k=0; k<N; k++) {
		c = i+j*k;
		if (S[c] == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	// local variables

	// fstream
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	// input
	fin >> N >> M;
	// main
	for (int i=0; i<=M; i++)
		for (int j=0; j<=M; j++)
			S[i*i+j*j] = 1;
	int MM = 2*M*M;
	for (int i=0; i<MM; i++) {
		for(int j = 1; j <= (MM-i)/ (N-1); j++){
			if (ok(i, j)) {
				cnt.push_back(pii(j, i));
			}
		}
	}
	// output
	sort(cnt.begin(), cnt.end());
	for (pii i : cnt) {
		fout << i.second<<" " << i.first<<endl;
	}
	if (cnt.empty()) {
		fout << "NONE"<<endl;
	}
	return 0;
}
```