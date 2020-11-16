# walk
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
// declare any global variables
int N, K;
bool visited[7510];
long long best[7510];
// declare any functions
ll min0(ll a, ll b){
	if(a<b) return a;
	return b;
}
ll max0(ll a, ll b){
	if(a>b) return a;
	return b;
}
void mst(){
	for(int i=1; i<=N; i++){
		best[i] = 1000000000000;
		visited[i] = false;
	}
	for(int i=1; i<=N; i++){
		int k = -1;
		for(int j=1; j<=N; j++){
			if(!visited[j] && (k==-1 or best[j]<best[k])) k=j;
		}
		visited[k] = true;
		for(int j=1; j<=N; j++){
			if(!visited[j]){
				long long temp = (2019201913*min0(k, j)+2019201949*max0(k, j))%2019201997;
				best[j] = min0(best[j], temp);
			}
		}
	}
}
int main() {

	// fstream
	ifstream fin ("walk.in");
	ofstream fout ("walk.out");

	// input

	fin >> N >> K;
	// main
	mst();

	sort(best, best+N+1);
//	for(int i=1; i<=N; i++){
//		cout <<"best["<<i<<"] = "<<best[i]<<endl;
//	}
	// output
	fout << best[N-K+1];
	//close
	fout.close();
	return 0;
}

```