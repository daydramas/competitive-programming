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
ll N, M, F[100010], S[100010], i, j;
multiset<ll> solver;
// declare any functions
int main() {

	// fstream
	ifstream fin ("hayfeast.in");
	ofstream fout ("hayfeast.out");

	// input
	fin >> N >> M;
	for(i=1; i<=N; i++) fin >> F[i] >> S[i];
	// main
	i=1, j=1;
	ll flavor = 0;
	ll ans = 1000000000000;
	while(j <= N+1){
		if(flavor < M){
			solver.insert(S[j]);
			flavor += F[j];
			j++;
			continue;
		}
		ans = min(ans, *solver.rbegin());
		solver.erase(solver.find(S[i]));
		flavor -= F[i];
		i++;
	}
	// output
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}
