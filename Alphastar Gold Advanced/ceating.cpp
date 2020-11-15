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

// structures / defines

// global variables
int N, D, H[50004];

// functions
bool work(long long h) {
	long long ch = 0; int hi = 1;
	for(int i=1; i<=D; i++) {
		while(true) {
			if(ch <= h) {
				if(hi == N+1) return false;
				ch += H[hi++];

			}
			if(ch > h) break;
		}
		ch /= 2;
	}
	return true;
}
int main() {
	// local variables

	// input
	cin >> N >> D;
	for(int i=1; i<=N; i++) cin >> H[i];
	// main
	long long min=0, max=10000000000000;
	while(min<max) {
		long long mid=(min+max)/2;
		if(!work(mid)) {
			max=mid;
		} else {
//			cout << "not"<<endl;
			min=mid+1;
		}
	}
	// output
	cout << min << endl;
	map<int, int > cnt;
	long long h = min;
	long long ch = 0; int hi = 1;
	int d=-1;
	for(int i=1; i<=D; i++) {
		while(true) {
			if(ch < h) {
//				cout <<i<<endl;
				if(hi == N+1) break;
				cout << i << endl;
				ch += H[hi++];
			}
			if(ch >= h) break;
		}
		ch /= 2;
//		cout << ch<< " " << hi << endl;
	}
	for(int i=hi; i<=N; i++) {
		cout << D << endl;
	}
	return 0;
}
