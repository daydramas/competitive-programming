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
	long long t, f;
	t = f = 0;
	for (int i=2; i<=N; i++) {
		int _i = i;
		while(_i % 10 == 0) _i /= 10;
		fact = fact*_i;
		while (fact % 10 == 0) fact /= 10;
	}
	// output
	while (fact % 10 == 0) fact /= 10;
	fout << fact % 10 << endl;
	return 0;
}