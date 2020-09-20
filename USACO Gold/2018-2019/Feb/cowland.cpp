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

// structures / defines
#define MAX_N 100000
#define MAX_D 17
// global variables
int N; int Q;
int E[MAX_N];
vector<int> edges[MAX_N];
int tree[MAX_N], depth[MAX_N], lca[MAX_N][MAX_D], label[MAX_N], topchain[MAX_N];
int segtree[MAX_N*4];
// functions
void initLca() {
	for(int d=1; d<MAX_D; d++) {
		for(int i=0; i<MAX_N; i++) {
			lca[i][d] = lca[lca[i][d-1]][d-1];
		}
	}
}
int getLCA(int a, int b) {
  if(depth[a] < depth[b]) swap(a, b);
  for(int d = MAX_D-1; d >= 0; d--) {
    if(depth[a] - (1<<d) >= depth[b]) {
      a = lca[a][d];
    }
  }
  for(int d = MAX_D-1; d >= 0; d--) {
    if(lca[a][d] != lca[b][d]) {
      a = lca[a][d];
      b = lca[b][d];
    }
  }
  if(a != b) {
    a = lca[a][0];
    b = lca[b][0];
  }
  return a;
}
void setUpSegTree(int idx, int l, int r, int i, int v) {
	if(l == r) segtree[idx] = v;
	else {
		int m = (l+r)/2;
		if(i <= m) setUpSegTree(2*idx, l, m, i, v);
		else setUpSegTree(2*idx+1, m+1, r, i, v);
		segtree[idx] = segtree[idx*2] ^ segtree[idx*2+1];
	}
}
void setUpSegTree(int i, int v) {
	return setUpSegTree(1, 0, MAX_N-1, i, v);
}
void dfsHld(int curr, int topPtr, int par, int& l) {
	label[curr] = l++;
	setUpSegTree(label[curr], E[curr]);
	topchain[curr] = topPtr;
	int lc = -1, lct = -1;
	for(int out : edges[curr]) {
		if(out == par) continue;
		if(tree[out] > lct) {
			lc = out, lct = tree[out];
		}
	}
	if(lc < 0 || lct < 0) return;
	dfsHld(lc, topPtr, curr, l);
	for(int out : edges[curr]) {
		if(out == par || out == lc) continue;
		dfsHld(out, out, curr, l);
	}
}
void dfsSize(int curr, int par) {
	tree[curr]++;
	for(int out : edges[curr]) {
		if(out == par) continue;
		depth[out] = depth[curr]+1;
		lca[out][0] = curr;
		dfsSize(out, curr);
		tree[curr] += tree[out];
	}
}
void setUp() {
	dfsSize(0, -1);
	initLca();
	int l = 0;
	dfsHld(0, 0, -1, l);
}
int QsegTree(int idx, int l, int r, int lhs, int rhs) {
  if(l >= lhs && r <= rhs) return segtree[idx];
  int ret = 0;
  int m = (l+r)/2;
  if(m >= lhs) ret ^= QsegTree(2*idx, l, m, lhs, rhs);
  if(m+1 <= rhs) ret ^= QsegTree(2*idx+1, m+1, r, lhs, rhs);
  return ret;
}
int QsegTree(int l, int r) {
	return QsegTree(1, 0, MAX_N-1, l, r);
}
int pathQ(int child, int par) {
	int ans = 0;
	while(child != par) {
		if(topchain[child] == child) {
			ans ^= E[child];
			child = lca[child][0];
		} else if (depth[topchain[child]] > depth[par]) {
			ans ^= QsegTree(label[topchain[child]], label[child]);
			child = lca[topchain[child]][0];
		} else {
			ans ^= QsegTree(label[par]+1, label[child]);
			break;
		}
	}
	return ans;
}
int query(int a, int b) {
	int r = getLCA(a, b);
	return pathQ(a, r) ^ pathQ(b, r) ^ E[r];
}
int main() {
	// local variables

	// input
	ifstream fin("cowland.in");
	ofstream fout("cowland.out");

	fin >> N >> Q;
	for(int i=0; i<N; i++) {
		fin >> E[i];
	}
	for(int i=1; i<N; i++) {
		int a, b; fin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	setUp();
	// main
	for(int i=0; i<Q; i++) {
		int c,a,b; fin >> c >> a >> b;
		if(c == 1) {
			a--; E[a] = b;
			setUpSegTree(label[a], b);
		} else {
			a--; b--;
			fout << query(a, b) << endl;
		}
	}
	// output

	return 0;
}
