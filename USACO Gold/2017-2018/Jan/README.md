<div align="center"> [atlarge.cpp](#0) | [mootube.cpp](#1) | [spainting.cpp](#2) </div>

# [atlarge.cpp](#0)
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
int N, K;
vector<int> adj[100001];
int depth[100001][3];
int cnt = 0;
//functions
void dfs1(int src, int pa) {
	depth[src][1] = depth[pa][1] + 1;
	if (adj[src].size() > 1) {
		for (int dest : adj[src]) {
			if (dest != pa) {
				dfs1(dest, src);
//				cout <<"depth[" << src<<"] = min ("<<depth[dest][2]+1<<", "<<depth[src][2]<<");"<<endl;
				depth[src][2] = min(depth[src][2], depth[dest][2] + 1);
//				cout <<"depth[" << src<<"] = min ("<<depth[dest][2]+1<<", "<<depth[src][2]<<endl;
			}
		}
	} else {
//		cout <<"size:" << adj[src].size() << ", "<<src << endl;
		depth[src][2] = 0;
	}
}
void dfs2(int src, int pa) {
	if (src != K)
		depth[src][2] = min(depth[src][2], depth[pa][2] + 1);
	for (int dest : adj[src]) {
		if (dest != pa) {
			dfs2(dest, src);
		}
	}
}
void dfs3(int src, int pa) {
	if ((depth[src][1] >= depth[src][2]) && (depth[pa][1] < depth[pa][2])) {
		cnt++;
	}
	for (int dest : adj[src]) {
		if (dest != pa) {
			dfs3(dest, src);
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("atlarge.in");
	ofstream fout("atlarge.out");

	// input
	fin >> N >> K;
	for (int i = 1; i < N; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		depth[i][1] = -1;
		depth[i][2] = 1000000000;
	}
	depth[0][1] = -1;
	depth[0][2] = -1;

	// main
	if (adj[K].size() == 1)
		cnt = 1;
	else {
		dfs1(K, 0);
		dfs2(K, 0);
		dfs3(K, 0);
	}
//	for(int i=1; i<=N; i++) {
//		cout << depth[i][1] << " " << depth[i][2] << endl;
//	}
	// output
	fout << cnt << endl;
	return 0;
}

```

# [mootube.cpp](#1)
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
struct E {
	int src, des, weight;
	E(int src, int des, int weight) : src(src), des(des), weight(weight) {}
};
struct b2sE {
  bool operator() (E i, E j) { return (i.weight>j.weight);}
} b2sE;

struct Q {
	int k, src, i;
	Q(int k, int src, int i) : k(k), src(src), i(i) {}
};
struct b2sQ {
  bool operator() (Q i, Q j) { return (i.k>j.k);}
} b2sQ;

// global variables
int N, Queries;
vector<E> edge;
vector<Q> query;
int pa[100001], sz[100001], ans[100001];

//functions
int find(int a) {
	if(pa[a] == a) return a;
	return find(pa[a]);
}
void merge(int a, int b) {
	int x=find(a), y=find(b);
	pa[y] = x;
	sz[x] += sz[y];
}
int main() {
	// local variables

	// fstream
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");

	// input
	fin >> N >> Queries;
	for(int i=1; i<N; i++) {
		int a,b,w; fin >> a >> b >> w;
		edge.push_back(E(a,b,w));
	}
	int M = N-1;
	for(int i=0; i<Queries; i++) {
		int a,b; fin >> a >> b;
		query.push_back(Q(a,b, i));
	}

	sort(edge.begin(), edge.end(), b2sE);
	sort(query.begin(), query.end(), b2sQ);
	// main
	for(int i=1; i<=N; i++) {
		pa[i]=i; sz[i]=1;
	}
	int in=0;
	for(Q q : query) {
		while(in<M && edge[in].weight>=q.k) {
			merge(edge[in].src, edge[in].des);
			in++;
		}
		ans[q.i] = sz[find(q.src)]-1; //because counting itself
	}
	for(int i=0; i<Queries; i++) {
		fout << ans[i] << endl;
	}
//	cout <<"__________"<<endl;
//	for(int i=1; i<=N; i++) cout << pa[i]<<" "<<sz[i]<<endl;
	// output

	return 0;
}

```

# [spainting.cpp](#2)
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

