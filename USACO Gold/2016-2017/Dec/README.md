<div align="center"> [checklist.cpp](#0) | [lasers.cpp](#1) | [moocast.cpp](#2) </div>

# [checklist.cpp](#0)
```cpp
///*
//============================================================================
// Name        : cpp_template.cpp
// Author      : Dong Liu
// Website     : dongliu.template.com
//============================================================================
//*/
//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <cstring>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//using namespace std;
//
//// declare any structures
//#define pii pair<int, int>
//#define MAXN 1010
//// declare any global variables
//int H, G;
//pii Holsteins[MAXN], Guernseys[MAXN];
//int dp[MAXN][MAXN][2];
//// declare any functions
//int square (int x){ return (x*x); }
//int dist(int x1, int y1, int x2, int y2){ return square(abs(x2-x1))+square(abs(y2-y1)); }
//int main() {
//
//	// fstream
//	ifstream fin ("checklist.in");
//	ofstream fout ("checklist.out");
//
//	// input
//	fin >> H >> G;
//	for(int i=1; i<=H; i++) fin >> Holsteins[i].first >> Holsteins[i].second;
//	for(int i=1; i<=G; i++) fin >> Guernseys[i].first >> Guernseys[i].second;
//	for(int i=0; i<=H; i++)
//		for(int j=0; j<=G; j++)
//			dp[i][j][0]=dp[i][j][1]=1000000000;
//	// main
//	dp[1][0][0]=0;
//	for(int i=0; i<H; i++){
//		for(int j=0; j<G; j++){
//			for(int k=0; k<=1; k++){
//				if(k == 0 && i == 0) continue;
//				if(k == 1 && j == 0) continue;
//
//				cout <<"dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k] << endl;
//				int fx, fy;
//				if(k==0){
//					fx=Holsteins[i-1].first; fy=Holsteins[i-1].second;
//				} else{
//					fx=Guernseys[j-1].first; fy=Guernseys[j-1].second;
//				}
//				dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + dist(Holsteins[i].first,Holsteins[i].second,fx,fy));
//				dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + dist(Guernseys[j].first,Guernseys[j].second,fx,fy));
//			}
//		}
//	}
//	// output
//	cout << dp[H][G][0] << endl;
//	//close
//	fout.close();
//	return 0;
//}
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
int H, G, hx[1001], hy[1001], gx[1001], gy[1001];
long long dp[1001][1001][2];
// declare any functions
void initialize(){
	ifstream cin ("checklist.in");
	cin >> H >> G;
	for(int i=0; i<H; i++) cin >> hx[i] >> hy[i];
	for(int i=0; i<G; i++) cin >> gx[i] >> gy[i];
	for(int i=0; i<=H; i++){
		for(int j=0; j<=G; j++){
			for(int k=0; k<=1; k++){
				dp[i][j][k] = 100000000000;
			}
		}
	}
}
int square (int x){
	return (x*x);
}
int dist(int x1, int y1, int x2, int y2){
	return square(abs(x2-x1))+square(abs(y2-y1));
}
void solve(){

	dp[1][0][0]=0;
	for(int i=0; i<=H; i++){
		for(int j=0; j<=G; j++){
			for(int k=0; k<=1; k++){
				if(k == 0 && i == 0) continue;
				if(k == 1 && j == 0) continue;

				int fx, fy;
				if(k==0){
					fx=hx[i-1]; fy=hy[i-1];
				} else if (k==1){
					fx=gx[j-1]; fy=gy[j-1];
				}
				if(i<H){
					dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + dist(hx[i],hy[i],fx,fy));
				}
				if(j<G){
					dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + dist(gx[j],gy[j],fx,fy));
				}
			}
		}
	}

}
void print_ans(){
	ofstream cout ("checklist.out");
	cout<<dp[H][G][0]<<endl;
}
int main() {


	// input
	initialize();
	// main
	solve();
	// output
	print_ans();

	return 0;
}

```

# [lasers.cpp](#1)
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
#define MAX (int)1e5+5
#define pii pair<int, int>
struct post {
	int x, y, in;
};
struct sbx {
	bool operator()(post i, post j) {
		return (i.x < j.x);
	}
} sbx;
struct sby {
	bool operator()(post i, post j) {
		return (i.y < j.y);
	}
} sby;

int N;
post postx[MAX], posty[MAX];
bool visited[MAX];
int dist[MAX];
pii I[MAX];
//functions
int main() {
	// local variables

	// fstream
	ifstream fin("lasers.in");
	ofstream fout("lasers.out");
	// input
	fin >> N;
	fin >> postx[0].x >> postx[0].y >> postx[N + 1].x >> postx[N + 1].y;
	postx[0].in = 0, postx[N + 1].in = N + 1;
	posty[0] = postx[0], posty[N + 1] = postx[N + 1];
	visited[0] = visited[N + 1] = false;
	for (int i = 1; i <= N; i++) {
		fin >> postx[i].x >> postx[i].y;
		postx[i].in = i;
		posty[i] = postx[i];
		visited[i] = false;
	}
	// main
	sort(postx, postx + N + 2, sbx);
	sort(posty, posty + N + 2, sby);
	for (int i = 0; i < N + 2; i++) {
		I[postx[i].in].first = i;
		I[posty[i].in].second = i;
	}
	queue<pii> Q;
	Q.push(make_pair(0, 0));
	visited[0] = true;
	int ans = -1;
	while (!Q.empty()) {
		int s = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if (s == N + 1) {
			ans = dist[s] - 1;
			break;
		}
		int i, j;
		//x
		if (d == 0 || d == 1) {
			i = I[s].first, j = I[s].first;
			while (i >= 0 && postx[I[s].first].x == postx[i].x) {
				int i2 = postx[i].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 2));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				i--;
			}
			while (j <= N + 1 && postx[I[s].first].x == postx[j].x) {
				int i2 = postx[j].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 2));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				j++;
			}
		}
		//y
		if (d == 0 || d == 2) {
			i = I[s].second, j = I[s].second;
			while (i >= 0 && posty[I[s].second].y == posty[i].y) {
				int i2 = posty[i].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 1));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				i--;
			}
			while (j <= N + 1 && posty[I[s].second].y == posty[j].y) {
				int i2 = posty[j].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 1));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				j++;
			}
		}

	}
	// output
	fout << ans << endl;
	return 0;
}

```

# [moocast.cpp](#2)
```cpp
/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
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

// declare any structures
#define ll long long
#define pii pair<long long, long long>
#define x first
#define y second
// declare any global variables
long long N;
pii cow[1010];
bool visited[1010];
// declare any functions
bool dist(long long i, long long j, long long X){
	long long d = (cow[i].x-cow[j].x)*(cow[i].x-cow[j].x) + (cow[i].y-cow[j].y)*(cow[i].y-cow[j].y);
	return (d <= X);
}
bool mst(long long X){
	long long connected = 0;
	queue<long long> solver; solver.push(1);
	memset(visited, false, sizeof(bool)*(N+1));
	visited[1] = true;
//	cout << "pushing 1"<<endl;
	while(!solver.empty()){
		long long in = solver.front();
		solver.pop();
		connected++;

		for(long long i=1; i<=N; i++){
			if(!visited[i] && dist(in, i, X)){
				solver.push(i);
//				cout << "pushing "<< i<<endl;
				visited[i] = true;
			}
		}
	}
	return (connected >= N);
}
int main() {

	// fstream
	ifstream fin ("moocast.in");
	ofstream fout ("moocast.out");

	// input
	fin >> N;
	for(long long i=1; i<=N; i++) fin >> cow[i].x >> cow[i].y;
	// main
	long long low = 0, high = 1000000000;
	while(low < high && low != high){
		long long mid = (low+high)/2;
//		cout << low << " " << high << " " << mid << endl;
		if(mst(mid)){
			high = mid;
		} else low = mid+1;
	}
	// output
	fout << low << endl;
	//close
	fout.close();
	return 0;
}

```

