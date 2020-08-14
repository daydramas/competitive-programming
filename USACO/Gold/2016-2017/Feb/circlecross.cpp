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
int BIT[100001];
//functions
int getSum(int pos) {
	if(pos == 0) return 0;
	int ans = 0;
	for(int i=pos+1; i!=0; i -= i&(-i)) {
		ans += BIT[i];
	}
//	cout<<"ans:"<<ans<<endl;
	return ans;
}
void addNode(int pos, int ans) {
	for(int i=pos+1; i<=2*N; i += i&(-i)) {
		BIT[i] += ans;
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("circlecross.in");
	ofstream fout("circlecross.out");

	// input
	fin >> N;
	vector<Pair> cowID(N, Pair(-1, -1));
	memset(BIT, 0, sizeof(N+1));
	for(int i=0; i<2*N; i++) {

		int x; fin >> x; x--;

		if(cowID[x].first == -1) {
			cowID[x].first = i;
		} else {
			cowID[x].second = i;
		}

	}
	int ans = 0;
	sort(cowID.begin(), cowID.end());
	for(int i=0; i<N; i++) {
//		cout <<i<<" : " << cowID[i].first<<" " << cowID[i].second<<endl;
		ans += getSum(cowID[i].second)-getSum(cowID[i].first);
		addNode(cowID[i].second, 1);
	}
	// main
//	for(int i=1; i<=2*N; i++) {
//		cout <<"i: "<<i<<" = "<<BIT[i]<<endl;
//	}
	fout <<ans <<endl;
//	int cnt = 0;
//	for(int i=0; i<N; i++) {
//		for(int j=i+1; j<N; j++) {
//			if(cowID[j].first < cowID[i].second) {
//				if(cowID[j].second > cowID[i].second) {
//					cnt++;
//				}
//			} else break;
//		}
//	}
//	fout << cnt << endl;
	// output
	return 0;
}
