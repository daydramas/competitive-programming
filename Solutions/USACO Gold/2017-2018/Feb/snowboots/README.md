# snowboots
```cpp
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
#define MAX (int) 1e5 + 0
// global variables
int N, B;
int tiles[MAX];
int range[MAX], depth[MAX];
int tin[MAX], bin[MAX];

//functions
bool sortTILE(int a, int b) {
	return tiles[a] > tiles[b];
}
bool sortBOOT(int a, int b) {
	return depth[a] > depth[b];
}
int main() {
	// local variables

	// fstream
	ifstream fin("snowboots.in");
	ofstream fout("snowboots.out");

	// input
	fin >> N >> B;
	for (int i = 0; i < N; i++) {
		fin >> tiles[i];
		tin[i] = i;
	}
	for (int j = 0; j < B; j++) {
		fin >> depth[j] >> range[j];
		bin[j] = j;
	}

// main
	sort(tin, tin + N, sortTILE);
	sort(bin, bin + B, sortBOOT);
	int pre[MAX], nxt[MAX], ans[MAX];
	for (int i = 1; i < N; i++) {
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	int t = 0;
	int maxstep = 1;
	for (int b = 0; b < B; b++) {
		while (t < N && depth[bin[b]] < tiles[tin[t]]) {
			nxt[pre[tin[t]]] = nxt[tin[t]];
			pre[nxt[tin[t]]] = pre[tin[t]];
			maxstep = max(maxstep, nxt[tin[t]] - pre[tin[t]]);
			t++;
		}
		if (range[bin[b]] < maxstep) {
			ans[bin[b]] = 0;
		} else
			ans[bin[b]] = 1;
	}
// output
	for (int i = 0; i < B; i++) {
		fout << ans[i] << endl;
	}
	return 0;
}

```