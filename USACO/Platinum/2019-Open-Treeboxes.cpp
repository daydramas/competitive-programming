#include "grader.h"
using namespace std;

#define MAX 100005

int dpt[MAX], sz[MAX];
vector<int> adj[MAX];
int x[MAX], y[MAX];
int lca[MAX][20];

void dfs(int src, int pa) {
	sz[src] = 1;
	for (int dest : adj[src]) {
		if (dest != pa) {
			dpt[dest] = dpt[src]+1;
			lca[dest][0] = src;
			dfs(dest, src);
			sz[src] += sz[dest];
		}
	}
}
void putPoint(int src, int pa, int mx, int Mx, int my, int My) {
	x[src] = mx;
	y[src] = my;
	setFarmLocation(src, mx, my);
	mx++; my++;
	for (int dest : adj[src]) {
		if (dest != pa) {
			putPoint(dest,src,Mx-sz[dest]+1,Mx,my,my+sz[dest]-1);
			my += sz[dest];
			Mx -= sz[dest];
		}
	}
}
int getLCA(int a, int b) {
	if (dpt[a] < dpt[b])
		swap(a, b);
	for (int d = 18 - 1; d >= 0; d--) {
		if (dpt[a] - (1 << d) >= dpt[b]) {
			a = lca[a][d];
		}
	}
	for (int d = 18 - 1; d >= 0; d--) {
		if (lca[a][d] != lca[b][d]) {
			a = lca[a][d];
			b = lca[b][d];
		}
	}
	if (a != b) {
		a = lca[a][0];
		b = lca[b][0];
	}
	return a;
}
void addRoad(int a, int b){
	// Fill in code here
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void buildFarms(){
	// Fill in code here
	dpt[0] = 0; dfs(0, -1);
	int N = getN();
	for (int d=1; d<=17; d++) {
		for (int i=0; i<N; i++) {
			lca[i][d] = lca[lca[i][d-1]][d-1];
		}
	}
	putPoint(0, -1, 1, N, 1, N);
}
void notifyFJ(int a, int b){
	// Fill in code here
	int A = getLCA(a, b);
	addBox(min(x[a], x[A]), min(y[a], y[A]), max(x[a], x[A]), max(y[a], y[A]));
	if (A == b) {
		return;
	}
	int orb = b;
	int dif = dpt[A]-dpt[b];
	int tb = b;
	for(int i = 17; i>=0; i--){
		if(lca[b][i]!=lca[0][0] && dpt[lca[b][i]]>dpt[A]){
			b = lca[b][i];
		}
	}
	addBox(min(x[b], x[orb]), min(y[b], y[orb]), max(x[b], x[orb]), max(y[b], y[orb]));
}
int main() {

}
