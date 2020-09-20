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
#define MAX 100005
#define pii pair<int, int>
// global variables
int N, M, C;
int S[MAX];
vector<pii> edge[MAX];
int early[MAX];
int cnt[MAX];
//functions
int main() {
	// local variables

	// fstream
	ifstream fin("timeline.in");
	ofstream fout("timeline.out");
	// input
	fin >> N >> M >> C;
	for (int i = 1; i <= N; i++) {
		fin >> S[i];
		early[i] = 0;
		cnt[i] = 0;
	}
	for (int i = 1; i <= C; i++) {
		int x, y, b;
		fin >> x >> y >> b;
		edge[y].push_back(pii(x, b));
		early[x]++;
	}
	// main
	stack<int> Stk;
	for (int i = 1; i <= N; i++) {
		if (early[i] == 0) {
			Stk.push(i);
		}
	}
	stack<int> order;
	while (!Stk.empty()) {
		int s = Stk.top();
		Stk.pop();
		order.push(s);
		for (pii d : edge[s]) {

			early[d.first]--;
			if (early[d.first] == 0) {
				Stk.push(d.first);
			}
		}
	}
	while (!order.empty()) {
		int o = order.top();
		order.pop();
		int mn = S[o];
		for (pii d : edge[o]) {
			mn = max(mn, cnt[d.first] + d.second);
		}
		cnt[o] = mn;
	}
	// output
	for (int i = 1; i <= N; i++) {
		fout << cnt[i] << endl;
	}
	return 0;
}
