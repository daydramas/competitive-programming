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

// structures / defines
#define Pair pair<int, int>
#define PPair pair<Pair, Pair>
struct interval {
	int Axis, pIn; bool on;
	interval(int Axis, int pIn, bool on): Axis(Axis), pIn(pIn), on(on) {}
};
struct s2b {
  bool operator() (interval i,interval j) { return (i.Axis<j.Axis);}
} s2b;
// global variables
int N;
PPair rectangle[1004];
vector<interval> I, I2;
bool mark[1004];
// functions

int main() {
	// local variables

	// input
	cin >> N;
	for(int i=1; i<=N; i++) {
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
//		x2++, y1++;
		rectangle[i] = PPair(Pair(x1, y2), Pair(x2, y1));
		I.push_back(interval(x1, i, true));
		I.push_back(interval(x2, i, false));
		mark[i] = false;
	}
	sort(I.begin(), I.end(), s2b);

	// main
	long long ans = 0;
	for(int i=0; i<I.size(); i++){
		if(i>0) {
			long long distX = I[i].Axis-I[i-1].Axis;
			I2.clear();
			for(int j=1; j<=N; j++) {
				if(mark[j]) {
					I2.push_back(interval(rectangle[j].first.second, j, true));
					I2.push_back(interval(rectangle[j].second.second, j, false));
				}
			}
			sort(I2.begin(), I2.end(), s2b);
			long long distY = 0; int onY = 0;
			for(int j=0; j<I2.size(); j++) {
				if(onY > 0) {
					distY += I2[j].Axis-I2[j-1].Axis;
				}
				if(I2[j].on) onY++;
				else if (!I2[j].on) onY--;
			}
			ans += distX*distY;
//			cout << distX <<  " " << distY << endl;
		}
		if(I[i].on) mark[I[i].pIn] = true;
		else if(!I[i].on) mark[I[i].pIn] = false;
	}

	// output
	cout << ans << endl;

	return 0;
}
