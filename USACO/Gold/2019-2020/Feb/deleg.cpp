/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

// structures/defines
#define MAX (int)1e5+5
// global variables
int N;
vector<int> adj[MAX];
vector<int> childsz[MAX];
int depth[MAX];
int cnt[MAX];
//functions
int dfs1(int i, int pa) {
	int sum = 0;
	for (int j : adj[i]) {
		if (j != pa) {
			depth[j] = depth[i] + 1;
			int tcs = dfs1(j, i);
			childsz[i].push_back(tcs);
			sum += tcs;
		}
	}
	return sum + 1;
}
int main() {
	// local variables

	// fstream
	ifstream fin("deleg.in");
	ofstream fout("deleg.out");
	// input
	fin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// main
	depth[1] = 0;
	dfs1(1, 1);
	for (int i = 1; i < N; i++) {
		if ((N - 1) % i == 0) {
			cnt[i] = 1;
		} else {
			cnt[i] = 0;
		}
	}
	for (int i = 4; i <= N; i++) {
		cnt[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		fout << cnt[i] << endl;
	}
	// output
	return 0;
}
