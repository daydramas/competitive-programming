<div align="center"> <a href="#bphotocpp">bphoto.cpp</a> | <a href="#cownavcpp">cownav.cpp</a> | <a href="#hpscpp">hps.cpp</a> </div>

# [bphoto.cpp](#0)
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

// global variables
int N, H[100000], sH[100000], Hs[100000];
//set<int> allL, bigL, allR, bigR;
int BIT[100001];
//functions
bool myfunction(int i, int j) {
	return (H[i] > H[j]);
}
void updateTree(int in, int value) {
	for (int i = in + 1; i <= N; i += i & (-i)) {
		BIT[i] += value;
	}
}
int getTree(int in) {
	int sum = 0;
	for (int i = in + 1; i != 0; i -= i & (-i)) {
		sum += BIT[i];
	}
	return sum;
}

int main() {
	// local variables

	// fstream
	ifstream fin("bphoto.in");
	ofstream fout("bphoto.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> H[i];
		sH[i] = i;
	}
	sort(sH, sH + N, myfunction);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int l = getTree(sH[i]);
		cout << H[sH[i]] << " l:" << l << " i:" << i << " r:" << i - l << endl;

		int r = i - l;
		int b = max(l, r);
		int s = min(l, r);
		if (s * 2 < b) {
			cnt++;
		}
		updateTree(sH[i], 1);
	}
	fout << cnt << endl;

//	cout << cnt << endl;
//	for(int i=0; i<N; i++) {
//		allR.insert(H[i]);
//	}
//	int cnt = 0;
//	for(int i=0; i<N; i++) {
//		bigR.clear();
//		for(set<int>::reverse_iterator it=allR.rbegin(); it!=allR.rend(); ++it) {
//			if(*it > H[i]) {
//				bigR.insert(*it);
//			} else {
//				break;
//			}
//		}
//		bigL.clear();
//		for(set<int>::reverse_iterator it=allL.rbegin(); it!=allL.rend(); ++it) {
//			if(*it > H[i]) {
//				bigL.insert(*it);
//			} else {
//				break;
//			}
//		}
//		int ma = max(bigR.size(), bigL.size());
//		int mi = min(bigR.size(), bigL.size());
//		if(2*mi < ma) {
//			cnt++;
//		}
//		allR.erase(H[i]);
//		allL.insert(H[i]);
//	}

// output
//	fout << cnt << endl;

	return 0;
}

```

# [cownav.cpp](#1)
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define MN 21
struct node {
	string moves;
	int move, lx, ly, rx, ry, ld, rd;
	node(string moves, int move, int lx, int ly, int rx, int ry, int ld, int rd) :
			moves(moves), move(move), lx(lx), ly(ly), rx(rx), ry(ry), ld(ld), rd(
					rd) {
	}
};
// global variables
int N;
bool barn[MN][MN];
int dp[MN][MN][MN][MN][4][4];
int X[4] = { 1, 0, -1, 0 };
int Y[4] = { 0, 1, 0, -1 };
//functions
bool outOfPosition(int x, int y) {
	return (x > N || x < 1 || y > N || y < 1);
}
void getNext(int *x, int *y, int d) {
	if (*x == N && *y == N) {
		return;
	}
	int nx = *x + X[d];
	int ny = *y + Y[d];
//	cout << "nx: " << nx << " ny: " << ny << endl;
	if (!barn[nx][ny] || outOfPosition(nx, ny)) {
		nx = *x, ny = *y;
	}
	*x = nx, *y = ny;
}
int main() {
	// local variables

	// fstream
	ifstream fin("cownav.in");
	ofstream fout("cownav.out");

	// input
	fin >> N;
	for (int i = N; i >= 1; i--) {
		string str;
		fin >> str;
//		cout << str << endl;
		for (int j = 1; j <= N; j++) {
			barn[i][j] = (str[j - 1] == 'E');
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) {
					for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							dp[i][j][k][l][m][n] = -1;
						}
					}
				}
			}
		}
	}
	// main
//	int a = 2, b = 2;
//	getNext(&a, &b, 3);
//	cout << "getNext(2, 2, 3) = " << a << " " << b << endl;
	dp[1][1][1][1][0][1] = 0;
	queue<node> Q;
	Q.push(node("", 0, 1, 1, 1, 1, 0, 1));
	int ans = 1000000001;
	while (!Q.empty()) {
		node f = Q.front();
		Q.pop();

//		if (f.moves == "FRFFLFFF") {
//			cout << f.move << endl;
//		}

		if (f.lx == N && f.rx == N && f.ly == N && f.ry == N) {
			ans = min(ans, dp[f.lx][f.ly][f.rx][f.ry][f.ld][f.rd]);
			cout << dp[f.lx][f.ly][f.rx][f.ry][f.ld][f.rd] << " " << f.moves
					<< endl;
		}
		int ta = dp[f.lx][f.ly][f.rx][f.ry][f.ld][f.rd] + 1;
		int lx, rx, ly, ry, ld, rd, nm = f.move + 1;
		//left
		ld = (f.ld + 1) % 4, rd = (f.rd + 1) % 4;
		if (-1 == dp[f.lx][f.ly][f.rx][f.ry][ld][rd]) {
			dp[f.lx][f.ly][f.rx][f.ry][ld][rd] = ta;
			Q.push(node(f.moves + "L", ta, f.lx, f.ly, f.rx, f.ry, ld, rd));
		}
		//right
		ld = (f.ld + 3) % 4, rd = (f.rd + 3) % 4;
		if (-1 == dp[f.lx][f.ly][f.rx][f.ry][ld][rd]) {
			dp[f.lx][f.ly][f.rx][f.ry][ld][rd] = ta;
			Q.push(node(f.moves + "R", ta, f.lx, f.ly, f.rx, f.ry, ld, rd));
		}
		//forward
		lx = f.lx, rx = f.rx, ly = f.ly, ry = f.ry, ld = f.ld, rd = f.rd;
		getNext(&lx, &ly, ld);
		getNext(&rx, &ry, rd);
		if (-1 == dp[lx][ly][rx][ry][ld][rd]) {
			dp[lx][ly][rx][ry][ld][rd] = ta;
			Q.push(node(f.moves + "F", ta, lx, ly, rx, ry, ld, rd));
		}
	}
// output
	fout << ans << endl;
	return 0;
}

```

# [hps.cpp](#2)
```cpp
//============================================================================
// Name        : cpp_template.cpp
// Author      : Dong Liu
// Website     : dongliu.template.com
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

// declare any structures

// declare any global variables
int N, K;
int move1[100001];
int dp[100001][21][4];
// declare any functions
bool win(int a, int b){
	if(a==2 and b==1) return true;
	if(a==3 and b==2) return true;
	if(a==1 and b==3) return true;
	return false;
}
int main() {

	// input
	ifstream fin ("hps.in");
	ofstream fout ("hps.out");

	fin >> N >> K;
	char read_move;
	for(int i=1; i<=N; i++){
		fin >> read_move;
		if(read_move=='H') move1[i] = 3;
		else if (read_move=='S') move1[i] = 2;
		else if (read_move=='P') move1[i] = 1;
	}
	for(int i=1; i<=N; i++){
		for(int j=0; j<=K; j++){
			for(int k=1; k<=3; k++){
				dp[i][j][k] = 0;
			}
		}
	}
	// main
	dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;
	for(int i=0; i<=N; i++){
		for(int j=0; j<=K; j++){
			for(int m=1; m<=3; m++){
				if(win(m, move1[i+1])){
					if(i+1 <= N) dp[i+1][j][m] = max(dp[i+1][j][m],dp[i][j][m]+1);
				} else {
					if(i+1 <= N) dp[i+1][j][m] = max(dp[i+1][j][m],dp[i][j][m]);
				}
				for(int n=1; n<=3; n++){
					if(n==m) continue;
					if(win(n, move1[i+1])){
						if(i+1 <= N && j-1 >= 0) dp[i+1][j-1][n] = max(dp[i+1][j-1][n],dp[i][j][m]+1);
					} else {
						if(i+1 <= N && j-1 >= 0) dp[i+1][j-1][n] = max(dp[i+1][j-1][n],dp[i][j][m]);
					}
				}
			}
		}
	}
	// output
	fout<<max(dp[N][0][3],max(dp[N][0][1],dp[N][0][2]));
	return 0;
}

```

