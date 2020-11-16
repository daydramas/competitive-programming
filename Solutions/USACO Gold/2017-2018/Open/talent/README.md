# talent
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
int N, W;
int w[250], t[250];
int dp[1000001];
int weight[1000001];
// global variables

//functions
bool possible(int y) {
//	memset(dp, 0, sizeof(W+1));
//	memset(weight, 1, sizeof(W+1));
	for(int i=0; i<=W;i++) {
//		weight[i] = 1;
		dp[i] = -100000000;
	}
	dp[0] = 0;
	for (int j = 0; j < N; j++) {
		long long value = 1000 * (long long) t[j] - y * (long long) w[j];
		int inc = w[j];
		for (int k = W; k >= 0; k--) {
			int k1 = min(W, k + inc);
			if (dp[k] != -100000000) {
				if (dp[k1] < dp[k] + value) {
					dp[k1] = dp[k] + value;
				}
			}
		}
	}

	return dp[W] >= 0;
//	dp[0] = 0; weight[0] = 0;
//	for(int i=0; i<N; i++) {
//		for(int j=W; j>=0; j--) {
//			int nt = dp[j] + t[i];
//			int aw = w[i];
//			int ni = min(W, weight[j]+aw);
//			cout <<nt<<"/"<<j+aw<<" vs "<<dp[ni]<<"/"<<weight[ni]<<endl;
//			if(nt/(double)(j+aw) > dp[ni]/(double)(weight[ni])) {
//				dp[ni] = nt;
//				weight[ni] = j+aw;
//			}
//		}
//	}
//	int tans = ((dp[W]/(double)weight[W])*1000);
//	cout <<R<<" : " <<dp[W] << " and "<<weight[W]<<endl;
//	return tans >= R;
}
int main() {
	// local variables

	// fstream
	ifstream fin("talent.in");
	ofstream fout("talent.out");

	// input
	fin >> N >> W;
	for(int i=0; i<N; i++) {
		fin >> w[i] >> t[i];
	}
	// main
	int s=0, b=250000001;
	while(s+1<b) {
		int m = (s+b)/2;
		if(possible(m)) {
			s = m;
		} else b = m;
	}
	// output
	fout << s << endl;
	return 0;
}

```