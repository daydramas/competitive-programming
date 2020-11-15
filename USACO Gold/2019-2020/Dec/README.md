<div align="center"> [cowmbat.cpp](#0) | [milkvisits.cpp](#1) | [pump.cpp](#2) </div>

# [cowmbat.cpp](#0)
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
string S;
int d[27][27];
int c[100001][27], ps[100001][27];
int dp[100001][27], dm[100001];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("cowmbat.in");
	ofstream fout("cowmbat.out");

	// input
	fin >> N >> M >> K;
	fin >> S;
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=M; j++) {
			fin >> d[i][j];
		}
	}
	// main
	for(int k=1; k<=M; k++) {
		for(int i=1; i<=M; i++) {
			for(int j=1; j<=M; j++) {
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			c[i][j] = d[S[i-1]-'a'+1][j];
			ps[i][j] = ps[i-1][j]+c[i][j];
		}
	}
	for(int i=0; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			dp[i][j] = 1061109567;
		}
	}
	for(int i=1; i<=N; i++) {
		dm[i] = 1000000000;
		for(int j=1; j<=M; j++) {
			dp[i][j] = min(dp[i][j], dp[i-1][j]+c[i][j]);
			if(i>=K) {
				dp[i][j] = min(dp[i][j], ps[i][j]-ps[i-K][j]+dm[i-K]);
			}
			dm[i] = min(dm[i], dp[i][j]);
		}
	}
	// output
	fout << dm[N] << endl;
	return 0;
}
```

# [milkvisits.cpp](#1)
```cpp
//#include <iostream>
//#include <map>
//#include <vector>
//#include <set>
//#include <queue>
//#include <algorithm>
//#include <iterator>
//#include <fstream>
//#include <cstring>
//#include <string>
//#include <iomanip>
//#include <iterator>
//#include <stack>
//#include <utility>
//using namespace std;
//
//// structures/defines
//
//// global variables
//int N, M;
//int cow[100001];
//vector<int> edge[100001];
//int depth[100001];
////int lca[100001][500];
//int pa[100001];
////functions
//void dfsLCA(int src, int parent) {
//	for(int dest : edge[src]) {
//		if(dest != parent) {
//			pa[dest] = src, depth[dest] = depth[src]+1;
//			dfsLCA(dest, src);
//		}
//	}
//}
//bool possible(int a, int b, int c) {
//	if(cow[a]==c || cow[b]==c) return true;
//	if(depth[a]<depth[b]) swap(a,b);
//	for(int i=(depth[a]-depth[b]); i>=1; i--) {
//		a = pa[a];
//		if(cow[a]==c) return true;
//	}
//	for(int i=depth[b]; i>=1; i--) {
//		if(cow[a]==c || cow[b]==c) return true;
//		if(a == b) break;
//		a = pa[a]; b = pa[b];
//		if(cow[a]==c || cow[b]==c) return true;
//	}
//	return false;
//}
//int main() {
//	// local variables
//
//	// fstream
//	ifstream fin("milkvisits.in");
//	ofstream fout("milkvisits.out");
//
//	// input
//	fin >> N >> M;
//	for(int i=1; i<=N; i++) {
//		fin >> cow[i];
//	}
//	for(int i=1; i<N; i++) {
//		int a,b; fin >> a >> b;
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//	}
//	// main
//	dfsLCA(1, -1);
//	for(int i=1; i<=M; i++) {
//		int a,b,c; fin >> a >> b >> c;
//		fout << possible(a,b,c);
//	}
//	// output
//
//	return 0;
//}
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
#define MN 100001
#define Pair pair<int, int>
// global variables
int N, M;
int T[MN];
vector<int> adj[MN], adj2[MN];
int D[MN], S[MN], E[MN]; int in;
int A[MN], B[MN], C[MN];
vector<int> parent;
vector<Pair> kind[MN];
bool cnt[MN];
//functions
bool ans(int a, int b) {
	return S[b]<=S[a] && E[b]>=E[a];
}
void dfs(int src, int pa) {
	S[src] = in++;
	for(int dst : adj[src]) {
		if(dst != pa) {
			D[dst] = D[src]+1;
			dfs(dst, src);
		}
	}
	E[src] = in-1;
}
void dfs2(int src, int pa) {
	parent.push_back(src);
	kind[T[src]].push_back(Pair(src, D[src]));
	for(int i : adj2[src]) {
		if(!kind[C[i]].empty() && !cnt[i]) {
			Pair b = kind[C[i]].back();
			if(b.first == src) cnt[i] = true;
			if(ans(A[i], b.first) && !ans(B[i], b.first)) {
//			if(A[i] == src && !ans(B[i], b.first)) {
				cnt[i] = true;
			}
			if(!ans(A[i], b.first) && ans(B[i], b.first)) {
//			if(B[i] == src && !ans(A[i], b.first)) {
				cnt[i] = true;
			}
			if(ans(A[i], b.first) && ans(B[i], b.first)) {
				int b2 = parent[b.second+1];
				if(ans(A[i], b2) && !ans(B[i], b2)) {
					cnt[i] = true;
				}
				if(!ans(A[i], b2) && ans(B[i], b2)) {
					cnt[i] = true;
				}
			}
		}
	}
	for(int dest : adj[src]) {
		if(dest != pa) {
			dfs2(dest, src);
		}
	}
	parent.pop_back(); kind[T[src]].pop_back();
}
int main() {
	// local variables

	// fstream
	ifstream fin("milkvisits.in");
	ofstream fout("milkvisits.out");

	// input
//	cout <<"hi"<<endl;

	fin >> N >> M;
	for(int i=1; i<=N; i++) fin >> T[i];
	for(int j=1; j<N; j++) {
		int x,y; fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// main
	D[1]=0, in=1; dfs(1, -1);
//	cout <<"hi"<<endl;
	for(int i=1; i<=M; i++) {
		fin >> A[i] >> B[i] >> C[i];
		adj2[A[i]].push_back(i);
		adj2[B[i]].push_back(i);
	}
//	cout <<"hi"<<endl;

	dfs2(1, -1);
//	cout <<"hi"<<endl;

	// output
	for(int i=1; i<=M; i++) {
		fout << cnt[i];
	}
	fout << endl;
	return 0;
}

```

# [pump.cpp](#2)
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
struct edge {
	int b, f, c;
	edge(int b, int f, int c) : b(b), f(f), c(c) {}
};
#define Pair pair<int, int>
#define node pair<int, Pair>
// global variables
int N, M;
vector<edge> edges[1001];
int dp[1001][1001];
long long ans = 0;
//functions
void spath() {
	dp[1][1000] = 0;
	priority_queue<node, vector<node>, greater<node> > Q;
	Q.push(node(0, Pair(1, 1000)));
	while(!Q.empty()) {
		int src = Q.top().second.first;
		int cost = Q.top().first;
		int flow = Q.top().second.second;
		Q.pop();
//		cout << src << " : "<<cost<<" "<<flow<<endl;
		if(src == N) {
			ans = max(ans,
					(long long)(flow*(1000000)/ (double)cost));

		}
		for(edge e : edges[src]) {
			int dest = e.b;
			int nflow = min(flow, e.f);
			int ncost = dp[src][flow] + e.c;
			if(dp[dest][nflow]>ncost || dp[dest][nflow] == 0) {
				dp[dest][nflow] = ncost;
				Q.push(node(ncost, Pair(dest, nflow)));
			}
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("pump.in");
	ofstream fout("pump.out");

	// input
	fin >> N >> M;
	for(int i=1; i<=M; i++) {
		int a,b,f,c; fin >> a >> b >> c >> f;
		edges[a].push_back(edge(b, f, c));
		edges[b].push_back(edge(a, f, c));
	}

	// main
	spath();

	// output
	fout << ans << endl;
	return 0;
}

```

