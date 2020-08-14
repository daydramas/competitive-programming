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
#define int_max 2147483640
// declare any global variables
int N, E[50001], B[50001], M[50001*2];
int ans = 0;
// declare any functions
int main() {

	// fstream
	ifstream fin ("cardgame.in");
	ofstream fout("cardgame.out");
	// input
	fin >> N;
	for(int i=0; i<N; i++){
		fin >> E[i];
		M[E[i]] = 1;
	}
	for (int i=1,j=0; i<=2*N; i++) if (!M[i]) B[j++]=i;
	sort(B,B+N); sort(E,E+N/2); sort(E+N/2,E+N);

	// main

	for (int i=(N+1)/2; i<N; i++) if (B[i]>E[ans]) ans++;
	for (int i=N/2,j=0; i<N; i++) if (E[i]>B[j]) ans++,j++;

	fout << ans << endl;

	// output

	//close
	fout.close();
	return 0;
}
