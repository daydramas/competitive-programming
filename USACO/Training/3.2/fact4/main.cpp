/*
 ID: dongliu3
 TASK: fact4
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define MOD 1000000000000

// global variables
int N;

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");

	// input
	fin >> N;

	// main
	long long fact = 1;
	for (int i=2; i<=N; i++) {
		fact = (fact*i) % MOD;
		if (fact % 10 == 0) fact /= 10;
	}
	// output
	while (fact % 10 == 0) fact /= 10;
	fout << fact % 10 << endl;
	return 0;
}