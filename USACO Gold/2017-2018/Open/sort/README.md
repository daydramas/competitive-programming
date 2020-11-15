# sort
```cpp
/*
 _____     ______              ______                _______
 |     \   |      |  |\     |  |             |           |     |      |
 |	    \  |      |  | \    |  |             |           |     |      |
 |      |  |      |  |  \   |  |   ___       |           |     |      |
 |      |  |      |  |   \  |  |      |      |           |     |      |
 |      /  |      |  |    \ |  |      |      |           |     |      |
 |_____/   |______|  |     \|  |______|      |______  ___|___  |______|

 ___   ___        ___             ___   ___   ___  ___
 __ | __  |   | |    |   \   / |   | |___  |___| |    |   | \
     |___| |___| |___ |___/   \ |___|  ___| |   | |___ |___| /

 */

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <stack>
#include <utility>
using namespace std;

// structures/defines

#define Pair pair<int, int>

// global variables
int N;
int B[100001];
Pair A[100001];
//functions
void construct(int in) {
	for (int i = in; i <= N; i += i & (-i)) {
		B[i]++;
	}
}
int compute(int in) {
	int sum = 0;
	for (int i = in; i > 0; i -= i & (-i)) {
		sum += B[i];
	}
	return sum;
}
int main() {
	// local variables

	// fstream
	ifstream fin("sort.in");
	ofstream fout("sort.out");

	// input
	fin >> N;
	for (int i = 1; i <= N; i++) {
		fin >> A[i].first;
		A[i].second = i;
		B[i] = 0;
	}
	// main
	int cnt = 1;
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) {
		construct(A[i].second);
		cnt = max(cnt, i - compute(i));
		cout << i << " " << compute(i) << endl;

	}
	// output

	fout << cnt << endl;
	return 0;
}

```