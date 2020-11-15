# 248
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
int N, number[250];
int DP[250][250];
// declare any functions
int main() {

	// fstream
	ifstream fin ("248.in");
	ofstream fout ("248.out");

	// input
	fin >> N;
	for(int i=1; i<=N; i++) fin >> number[i];
	for(int i=1; i<=N; i++) DP[i][i] = number[i];
	// main
	int ans = 0;
	for(int length=1; length<=N; length++){
		for(int i=1; (i+length-1)<=N; i++){
			int j = (i+length-1);
			for(int k=1; k<j; k++){
				if(DP[i][k]==DP[k+1][j] and DP[i][k]!=0){
					DP[i][j] = max(DP[i][j], DP[i][k]+1);
				}
			}
			ans = max(ans, DP[i][j]);
		}
	}
	// output
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}

```