/*
 ID: dongliu3
 TASK: fcolor
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
const int maxn = 100005;

// global variables
int N, M;
vector<int> loved[maxn];

//functions
int main() {
	// local variables

	// fstream
	ifstream fin("fcolor.in");
	ofstream fout("fcolor.out");
	// input
	fin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a, b;
		fin >> a >> b;
		loved[a].push_back(b);
	}
	// main
	for (int i = 1; i <= N; i++) {
		if (loved[i].size() >= 2) {
//			for (int j=0; j<loved[i].size(); j++)
		}
	}
	// output

	return 0;
}
