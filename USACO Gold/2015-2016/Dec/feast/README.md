# feast
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

// declare any global variables
int T, A, B;
bool dp[2][5000001];

// declare any functions
void add(){
	for(int j=0; j<2; j++){
		for(int i=0; i<=T; i++){
			if(i+A <= T){
				dp[j][i+A] = dp[j][i+A]||dp[j][i];
			}
			if(i+B <= T){
				dp[j][i+B] = dp[j][i+B]||dp[j][i];
			}
		}
	}
}
void divide(){
	for(int i=1; i<=T; i++){
		dp[1][i/2] = dp[1][i/2] || dp[0][i];
	}
}
void both(){
	for(int j=0; j<2; j++){
		for(int i=0; i<=T; i++){
			if(i+A <= T){
				dp[j][i+A] = dp[j][i+A]||dp[j][i];
			}
			if(i+B <= T){
				dp[j][i+B] = dp[j][i+B]||dp[j][i];
			}
			if(j==0){
				dp[1][i/2] = dp[1][i/2] || dp[j][i];
			}
		}
	}
}
int main() {

	// fstream
	ifstream fin ("feast.in");
	ofstream fout ("feast.out");

	// input
	fin >> T >> A >> B;
	// main
	for(int i=0; i<2; i++){
		for(int j=0; j<=T; j++) dp[i][j] = false;
	}
	dp[0][0] = true;
//	add();
//	divide();
//	add();
	// output
	both();
	int ans = T;
	while(!dp[1][ans]) ans--;
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}

```