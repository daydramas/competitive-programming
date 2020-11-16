# spainting
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
int N, M, K;
int dp[1000001][2];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("3.in");
	ofstream fout("spainting.out");

	// input
	fin >> N >> M >> K;
	for(int i=0; i<=N; i++){
		dp[i][0]= 0; dp[i][1] = 0;
	}
	// main
	dp[1][0] = 1;
	for(int i=1; i<=N; i++) {
		cout <<"1; " <<dp[i][0] <<" , "<<dp[i][1]<<endl;
		if(i+K-1 <= N) {
			dp[i+K-1][1] += dp[i][0];
			dp[i+K-1][1] %= 1000000007;
			cout <<"2; dp["<<i+K-1<<"][1] = "<<dp[i+K-1][1]<<endl;

//			dp[i+K-1][1] += dp[i][1]+1;
		}
		if(i+1 <= N) {
//			if(dp[i][1] == 0) dp[i+1][1] += M;
//			else
				dp[i+1][1] += dp[i][1]*M;
			dp[i+1][1] %= 1000000007;

//			if(dp[i][0] == 0) dp[i+1][0] += M;
//			else
				dp[i+1][0] += (dp[i][0]*M)+M;
			dp[i+1][0] %= 1000000007;
//			dp[i+1][0] = dp[i][1]+M;
		}
		cout <<endl;
	}
	// output
	cout << dp[N][1] << endl;
	return 0;
}

```