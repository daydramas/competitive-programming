# snakes
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables

// declare any functions

int main() {
	// declare any local variables
	int N, K, groups[401], DP[401][400];
	int total_snakes = 0;
	int maxn_snakes_in_group = 0;
	// fstream
	ifstream fin ("snakes.in");
	ofstream fout ("snakes.out");

	// input
	fin >> N >> K;
	for(int i=1; i<=N; i++){
		fin >> groups[i];
		total_snakes += groups[i];

		maxn_snakes_in_group = max(maxn_snakes_in_group, groups[i]);
		DP[i][0] = maxn_snakes_in_group*i;

		for(int j=1; j<=K; j++){
			DP[i][j] = 1000000000;
			int snakes = groups[i];

			for(int b=i-1; b>=0; b--){
				DP[i][j] = min(DP[i][j], DP[b][j-1]+(snakes*(i-b)));
				snakes = max(snakes, groups[b]);
			}
		}
	}

	// output
	fout<< DP[N][K]-total_snakes <<endl;
	fout.close();
	return 0;
}

```