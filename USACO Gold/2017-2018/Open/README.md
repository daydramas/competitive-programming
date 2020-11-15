<div align="center"> <a href="#milkordercpp">milkorder.cpp</a> | <a href="#sortcpp">sort.cpp</a> | <a href="#talentcpp">talent.cpp</a> </div>

# [milkorder.cpp](#0)
```cpp
#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define Pair pair<int, int>
// global variables
int N, M;
vector<Pair> observation[50000];
vector<int> after[100000];
int before[100000],
answer[100000];
//functions
bool ok(int X) {
	for (int i = 0; i < N; i++) {
		after[i].clear();
		before[i] = 0;
	}
	for (int i = 0; i <= X; i++) {
		for (Pair o : observation[i]) {
			after[o.first].push_back(o.second);
			before[o.second]++;
		}
	}
	priority_queue<int, vector<int>, greater<int> > Q;
	for (int i = 0; i < N; i++) {
		if (before[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		if (Q.empty()) {
			return false;
		}
		int t = Q.top();
		Q.pop();
		answer[i] = t;
		for (int a : after[t]) {
			before[a]--;
			if (!before[a]) {
				Q.push(a);
			}
		}
	}
	return true;
}
int main() {
	// local variables

	// fstream
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");

	// input
	fin >> N >> M;
	for (int i = 0; i < M; i++) {
		int m;
		fin >> m;
		int px = -1;
		for (int j = 0; j < m; j++) {
			int x;
			fin >> x;
			x--;
			if (j) {
				observation[i].push_back(Pair(px, x));
			}
			px = x;
		}
	}
	// main
	int s = 0, b = M - 1, X = -1;
	while (s + 1 < b) {
		int m = (s + b) / 2;
		if (ok(m)) {
			X = m;
			s = m;
		} else {
			b = m;
		}
	}
	ok(s);

	// output
	for (int i = 0; i < N; i++) {
		fout << ++answer[i];
		if(i < N-1) fout << " ";
		else fout << endl;
	}
	return 0;
}

```

# [sort.cpp](#1)
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

# [talent.cpp](#2)
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

