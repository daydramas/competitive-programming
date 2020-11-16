# milkvisits
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