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
int N, M;
int spend[100004];

// functions

int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		cin >> spend[i];
	}
	// main
	int min=0, max=1000000000;
	while(min<max) {
		int mid = (min+max)/2;

		int sum = 0;
		int group = 1;
		for(int i=1; i<=N; i++) {
			if(spend[i]>mid) {
				group = M+1;
				break;
			}
			if(sum+spend[i] > mid) {
				group++, sum = 0;
			}
			sum += spend[i];
		}
		if(group <= M) {
			max = mid;
		} else {
			min = mid+1;
		}
	}

	// output
	cout << min << endl;
	return 0;
}
