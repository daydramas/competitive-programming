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
