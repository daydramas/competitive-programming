# checklist
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