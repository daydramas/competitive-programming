<div align="center"> [dirtraverse.cpp](#0) | [snowboots.cpp](#1) | [taming.cpp](#2) </div>

# [dirtraverse.cpp](#0)
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
 __  | __  |   | |    |   \   / |   | |___  |___| |    |   | \
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
int length[100000];
vector<int> adj[100000];
vector<int> folder;
long long childSize[100000]; int numChild[100000], parent[100000];
long long ans[100000];
//functions

void dfs(int src, int pa) {
	parent[src] = pa;
	childSize[src] = 0;
	numChild[src] = 0;
	if (adj[src].size() == 0) numChild[src] = 1;
	for (int dest : adj[src]) {
		if (dest == pa)
			continue;
		dfs(dest, src);
		numChild[src] += numChild[dest];
		if (adj[dest].size()) {
//			childSize[src] += (numChild[dest]-1)*length[dest];
//			childSize[src]++;
			childSize[src] += (numChild[dest] * (length[dest] + 1))
					+ childSize[dest];
//			cout <<"1childSize["<<src<<"] += "<<(numChild[dest]-1)*length[dest]<<endl;
//			cout <<"2childSize["<<src<<"] += "<<1<<endl;
		} else {
			childSize[src] += length[dest];
		}
//
//		if(adj[dest].size()) childSize[src]++;
//		cout <<"3childSize["<<src<<"] += "<<length[dest]+childSize[dest]<<endl;

	}
}
void dfs2(int src, int pa, long long cnt, int level) {
	for(int pre : adj[src]) {
		if(pre != pa && adj[pre].size()) {
			long long pcnt = cnt;
			cnt += (numChild[0]-numChild[pre])*(3);
			cnt -= (length[pre]+1)*numChild[pre];
       		ans[pre] = cnt;
       		dfs2(pre, src, cnt, ++level);
       		cnt = pcnt;
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("dirtraverse.in");
	ofstream fout("dirtraverse.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		int sz;
		fin >> name >> sz;
		length[i] = name.size();
		if(sz) {
			folder.push_back(i);
		}
		ans[i] = 1000000000;
		for (int j = 0; j < sz; j++) {
			int x;
			fin >> x;
			adj[i].push_back(--x);
		}
	}
	// main
	dfs(0, -1);

//	for (int i = 0; i < N; i++) {
//		cout << "childs: " << i << " = " << numChild[i] << endl;
//	}
//	parent[0] = -1;
	ans[0] = childSize[0];
	dfs2(0, -1, childSize[0], 1);
	long long cnt = 10000000000;
	for(int i=0; i<N; i++) {
		if(adj[i].size()){
			cnt = min(cnt, ans[i]);
		}
	}
	fout << cnt << endl;
//	for (int i : folder) {
////		if (adj[i].size()) { // folder
////			int dot = 0;
////			long long tcnt = childSize[i];
////			cout <<i<<" = " << tcnt<<endl;
////			int pa = i, pre = -1, childDone = numChild[i];
////			while(pa != parent[pa]) {
////				pre = pa, pa = parent[pa], dot++;
////				tcnt += (3*dot*(numChild[pa]-childDone))+(childSize[pa]-childSize[pre]);
////				cout <<i<<" += "<< 2*dot*(numChild[pa]-childDone)<<" +  " << childSize[pa]<<" - "<<childSize[pre]<<endl;
////				childDone += numChild[pa]-numChild[pre];
////			}
////			cout << tcnt<<endl<<endl;
////			ans = min(ans, tcnt);
//			int level = 1;
//			long long tcnt = childSize[i];
//			int pre=i, src=parent[i];
//			while (src!=-1) {
//           		tcnt += childSize[src]-(numChild[pre]*(length[pre]+1)+childSize[pre]);
//           		tcnt += (numChild[src]-numChild[pre])*(3*level);
//                pre=src; src=parent[src]; level++;
//			}
////			long long tcnt = childSize[i];
////			int pa = i, src = -1;
////			cout<<endl;
////			cout <<"i: "<< i << " " << tcnt <<endl;
////			while (src != pa){
////				src = pa, pa = parent[pa], level++;
////				cout << src << " " << pa << " " << childSize[pa] << endl;
////				tcnt += childSize[pa] - (numChild[src] * (length[src] + 1) + childSize[src]);
//////				tcnt += (childSize[pa] - childSize[src]) * (3 * level);
////
////				tcnt += (numChild[pa]-numChild[src]) * (3* level);
////				cout <<"tcnt: "<<tcnt<<endl;
////
////			}
//			ans = min(ans, tcnt);
////		}
//	}
	// output
	return 0;
}

```

# [snowboots.cpp](#1)
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

# [taming.cpp](#2)
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

// structures/defines
// global variables
int N;
int mylogger[101];
int dp[101][101][101];

//functions
int main() {
	// local variables
//	cout << "hi" << endl;
	// fstream
	ifstream fin("taming.in");
	ofstream fout("taming.out");
//	fout << "hi" << endl;
	// input
//	cout << "hi" << endl;
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> mylogger[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= N; k++) {
				dp[i][j][k] = 1000000000;
			}
		}
	}
//	cout << "hi" << endl;
	// main
	dp[0][0][1] = !(mylogger[0] == 0);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 1; k <= i + 1; k++) {
//				if (k > i || j > i || j > k)
//					continue;
				if (j < i)
					dp[i][j][k] = dp[i - 1][j][k];
				else
					for (int j1 = 0; j1 < i; j1++)
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j1][k - 1]);
				if (mylogger[i] != i - j)
					dp[i][j][k]++;
//				cout << "dp[" << i << "][" << j << "][" << k << "] = "
//						<< dp[i][j][k] << endl;
			}
		}
	}
//	cout << "hi" << endl;
	// output
	for (int a = 1; a <= N; a++) {
		int ans = 1000000000;
		for (int i = 0; i < N; i++) {
			ans = min(ans, dp[N - 1][i][a]);
		}
		cout << ans << endl;
		fout << ans << endl;
	}
	return 0;
}

```

