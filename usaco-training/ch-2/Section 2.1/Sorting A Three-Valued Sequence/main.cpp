/*
 ID: dongliu3
 TASK: sort3
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int S[1000], SS[1000];
int cnt;
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	// input
	fin >> N; cnt = 0;
	for (int i=0; i<N; i++) {
		fin >> S[i];
		SS[i] = S[i];
	}
	// main
	sort(SS, SS+N);
	for (int i=0; i<N; i++) {
		if (S[i] == SS[i]) continue;
		for (int j=i+1; j<N; j++) {
			if (S[i] == SS[j] && S[j] == SS[i]) {
				cnt++;
				swap(S[i], S[j]);
				break;
			}
		}
	}
	for (int i=0; i<N; i++) {
		if (SS[i] != S[i] && S[i] == 1) {
			cnt += 2;
		}
	}
	// output
	fout << cnt << endl;
	return 0;
}