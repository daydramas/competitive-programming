# barnpainting
```cpp
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
long long N, K;
vector<long long> adj[100001];
long long color[100001];
long long dp[100001][5];
//functions
long long solve(long long src, long long srcC, long long pa, long long paC) {
//	cout << src<< " " << srcC << " " << pa << " " << paC << endl;
	if((srcC == paC)||(color[src]>=1 && color[src]!=srcC)) {
//		cout << "1" << endl;
		return 0;
	}
	if(dp[src][srcC] >=0) return dp[src][srcC];
	dp[src][srcC] = 1;
	for(long long dest : adj[src]) {
		if(dest == pa) continue;
		long long mul = 0;
		for(long long c=1; c<=3; c++) {
			mul += solve(dest, c, src, srcC);
			mul %= 1000000007;
		}
		dp[src][srcC] *= mul;
		dp[src][srcC] %= 1000000007;
	}
//	cout << dp[src][srcC] << " ";
	return dp[src][srcC];
}
int main() {
	// local variables

	// fstream
	ifstream fin("barnpainting.in");
	ofstream fout("barnpainting.out");

	// input
	fin >> N >> K;
	for(long long i=1; i<N; i++) {
		long long x,y; fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(long long i=1; i<=N; i++) {
		dp[i][1] = dp[i][2] = dp[i][3] = -1;
		color[i] = -1;
//		cout << "color["<<i<<"] = "<<color[i] << endl;
	}
	for(long long i=1; i<=K; i++) {
		long long x,y; fin >> x >> y;
		color[x] = y;
	}
	long long s1 = solve(1, 1, -1, -1); //cout << endl;
	long long s2 = solve(1, 2, -1, -1); //cout << endl;
	long long s3 = solve(1, 3, -1, -1); //cout << endl;
	fout << (s1+s2+s3)%1000000007 << endl;
	return 0;
}

```