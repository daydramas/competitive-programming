# art2
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
int N;
int shell[100001];
int small[100001], big[100001];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("art2.in");
	ofstream fout("art2.out");

	// input
	fin >> N;
	for(int i=0; i<=N; i++) {
		small[i] = 1000000000;
		big[i] = -1;
	}
	for(int i=1; i<=N; i++) {
		fin >> shell[i];

		small[shell[i]] = min(small[shell[i]], i);
		big[shell[i]] = max(big[shell[i]], i);
	}
	// main
	stack<int> S;
	int ans = 0;
	for(int i=1; i<=N; i++) {
		int color = shell[i];
		if(color == 0) continue;
//		cout <<"color: "<<shell[i] << endl;
		if(small[color] == i) {
			S.push(color);
			ans = max(ans, (int)S.size());
		}
//		cout <<"top: "<<S.top() << endl;
		if(S.top() != color) {
//			cout << "weird" << endl;
			ans = -1;
			break;
		}
		if(big[color] == i) {
			S.pop();
		}
	}
	// output
	fout << ans << endl;
	return 0;
}

```