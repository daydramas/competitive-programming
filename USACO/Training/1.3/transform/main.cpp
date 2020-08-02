/*
 ID: dongliu3
 TASK: transform
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define MAP2D map<int, map<int, bool> >
#define MN 15
// global variables
int N;
MAP2D before, after;

// functions
MAP2D rotate90(MAP2D A) {
	MAP2D temp;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			temp[i][j] = A[N-j+1][i];
		}
	}
	return temp;
}
MAP2D reflect(MAP2D A) {
	MAP2D temp;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			temp[i][N+1-j] = A[i][j];
		}
	}
	return temp;
}
int main() {
	// local variables

	// fstream
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	// main
	fin >> N;
	for (int i=1; i<=N; i++) {
		string str; fin >> str;
		for (int j=1; j<=N; j++) {
			before[i][j] = str[j-1] == '@';
		}
	}
	for (int i=1; i<=N; i++) {
		string str; fin >> str;
		for (int j=1; j<=N; j++) {
			after[i][j] = str[j-1] == '@';
		}
	}
	// output
	if (rotate90(before) == after) {
		fout << "1" << endl;
	} else if (rotate90(rotate90(before)) == after) {
		fout << "2" << endl;
	} else if (rotate90(rotate90(rotate90(before))) == after) {
		fout << "3" << endl;
	} else if (reflect(before) == after) {
		fout << "4" << endl;
	} else if (rotate90(reflect(before)) == after || rotate90(rotate90(reflect(before))) == after || rotate90(rotate90(rotate90(reflect(before)))) == after) {
		fout << "5" << endl;
	} else if (before == after) {
		fout << "6" << endl;
	} else fout << "7" << endl;
	return 0;
}