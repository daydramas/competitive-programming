# bphoto
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

// global variables
int N, H[100000], sH[100000], Hs[100000];
//set<int> allL, bigL, allR, bigR;
int BIT[100001];
//functions
bool myfunction(int i, int j) {
	return (H[i] > H[j]);
}
void updateTree(int in, int value) {
	for (int i = in + 1; i <= N; i += i & (-i)) {
		BIT[i] += value;
	}
}
int getTree(int in) {
	int sum = 0;
	for (int i = in + 1; i != 0; i -= i & (-i)) {
		sum += BIT[i];
	}
	return sum;
}

int main() {
	// local variables

	// fstream
	ifstream fin("bphoto.in");
	ofstream fout("bphoto.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> H[i];
		sH[i] = i;
	}
	sort(sH, sH + N, myfunction);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int l = getTree(sH[i]);
		cout << H[sH[i]] << " l:" << l << " i:" << i << " r:" << i - l << endl;

		int r = i - l;
		int b = max(l, r);
		int s = min(l, r);
		if (s * 2 < b) {
			cnt++;
		}
		updateTree(sH[i], 1);
	}
	fout << cnt << endl;

//	cout << cnt << endl;
//	for(int i=0; i<N; i++) {
//		allR.insert(H[i]);
//	}
//	int cnt = 0;
//	for(int i=0; i<N; i++) {
//		bigR.clear();
//		for(set<int>::reverse_iterator it=allR.rbegin(); it!=allR.rend(); ++it) {
//			if(*it > H[i]) {
//				bigR.insert(*it);
//			} else {
//				break;
//			}
//		}
//		bigL.clear();
//		for(set<int>::reverse_iterator it=allL.rbegin(); it!=allL.rend(); ++it) {
//			if(*it > H[i]) {
//				bigL.insert(*it);
//			} else {
//				break;
//			}
//		}
//		int ma = max(bigR.size(), bigL.size());
//		int mi = min(bigR.size(), bigL.size());
//		if(2*mi < ma) {
//			cnt++;
//		}
//		allR.erase(H[i]);
//		allL.insert(H[i]);
//	}

// output
//	fout << cnt << endl;

	return 0;
}

```