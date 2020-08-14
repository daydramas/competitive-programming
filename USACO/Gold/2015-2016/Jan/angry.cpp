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
struct s2b {
	bool operator()(ll i, ll j) {
		return (i < j);
	}
} s2b;
// declare any global variables
ll N;
vector<ll> loc;
ll cleft = 1000000000, cright = 0;
// declare any functions
bool possibleFirst(ll start, ll r) {
	if (cleft < start - r) {
		long curr = loc[lower_bound(loc.begin(), loc.end(), start - r)
				- loc.begin()];
		long currRadius = r - 2;
		while (curr != cleft) {
			long next = loc[lower_bound(loc.begin(), loc.end(),
					curr - currRadius) - loc.begin()];
			if (next >= curr) {
				return false;
			}
			curr = next;
			currRadius -= 2;
		}
	}
	return true;
}
bool possibleLast(ll start, ll r) {
	if (cright > start + r) {
		long curr = loc[upper_bound(loc.begin(), loc.end(), start + r)
				- loc.begin() - 1];
		long currRadius = r - 2;
		while (curr != cright) {
			long next = loc[upper_bound(loc.begin(), loc.end(),
					curr + currRadius) - loc.begin() - 1];
			if (next <= curr) {
				return false;
			}
			curr = next;
			currRadius -= 2;
		}
	}
	return true;
}
int main() {

	// fstream
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		int L;
		fin >> L;
		loc.push_back(2 * L);
	}
	sort(loc.begin(), loc.end(), s2b);
	cleft = loc[0];
	cright = loc[N - 1];
	// main
//	for(int i=0; i<N; i++) cout << loc[i] << endl;
//	cout << endl;
//	cout << upper_bound (loc.begin(), loc.end(), 6)-loc.begin()-1 << endl;
//	cout << lower_bound (loc.begin(), loc.end(), 20)-loc.begin()-1 << endl;
	ll min = 0;
//	cout << cleft << " " << cright << endl;
	ll max = 1000000000;
	while (min != max) {
		ll mid = (min + max) / 2;
		ll l = cleft;
		ll r = cright;
		while (l < r) {
			long m = (l + r + 1) / 2;
			if (possibleFirst(m, mid)) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		if (possibleLast(l, mid)) {
//			cout << min << " " << max <<" " << mid <<" true "<<endl;
			max = mid;
		} else {
//			cout << min << " " << max <<" " << mid <<" false "<<endl;
			min = mid + 1;
		}
	}
	// output
	fout << fixed << setprecision(1) << min / 2.0 << endl;
	//close
	fout.close();
	return 0;
}
