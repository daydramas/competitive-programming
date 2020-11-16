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
int cow[100000];
int btree[100001];
//functions;
void initBtree(int i) {
//	int oi = i;
	i++;
	for(; i<=N; i+=i&(-i)) {
		btree[i] += 1;
	}
//	cout << oi+1 << ": ";
//	for(int i1=1; i1<=N; i1++) {
//		cout<<btree[i1]<<" ";
//	} cout << endl;
}
int getSum(int i) {
	i++; int cnt=0;
	for(; i>0; i-=i&(-i)) {
		cnt += btree[i];
	}
	return cnt;
}
int main() {
	// local variables

	// fstream
	ifstream fin("sleepy.in");
	ofstream fout("sleepy.out");

	// input
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> cow[i];
		cow[i]--;
	}

	// main
	int K = N-1;
	while(K>0 && cow[K-1]<cow[K]) {
		K--;
	}
	fout << K << endl;
	for(int i=K; i<N; i++) initBtree(cow[i]);
	for(int i=0; i<K; i++) {
		fout << (K-i-1)+getSum(cow[i]);
		if(i!=K-1) fout <<" ";
		initBtree(cow[i]);
	}
	// output
	fout << endl;
	return 0;
}
