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
#define x first
#define y second
struct interval {
	int xAxis; int pIn; bool open;
	interval(int xAxis, int pIn, bool open) : xAxis(xAxis), pIn(pIn), open(open) {}
};
struct s2b {
  bool operator() (interval i,interval j) { return (i.xAxis<j.xAxis);}
} s2b;
// global variables
int X, Y, I;
PPair Plow[1004];
bool visited[1004];
vector <interval> inter;
// functions

int main() {
	// local variables

	// input
	cin >> X >> Y >> I;
	for(int i=1; i<=I; i++) {
		cin >> Plow[i].x.x >> Plow[i].x.y >> Plow[i].y.x >> Plow[i].y.y;
		inter.push_back(interval(Plow[i].x.x, i, true));
		inter.push_back(interval(Plow[i].y.x+1, i, false));
		visited[i] = false;
	}
	sort(inter.begin(), inter.end(), s2b);
	// main
	int ans = 0;
	for(int i=0; i<(I*2); i++) {
		if(i!=0) {
			int dist = inter[i].xAxis-inter[i-1].xAxis;
//			if(i !=(I*2)-1 && i != 1) dist++;
			vector<interval> inter2;
			for(int j=1; j<=I; j++) {
				if(visited[j]) {
					inter2.push_back(interval(Plow[j].x.y, j, true));
					inter2.push_back(interval(Plow[j].y.y+1, j, false));
				}
			}
			sort(inter2.begin(), inter2.end(), s2b);
			int on = 0;
			int add = 0;
//			cout << "inter2size: "<<inter2.size()<<endl;
			for(int j=0; j<(inter2.size()); j++) {
//				cout << inter2[j].xAxis<<endl;
				if(j!=0 && on>0){
					add += inter2[j].xAxis-inter2[j-1].xAxis;
//					cout << "adding: "<<inter2[j].xAxis-inter2[j-1].xAxis<<endl;
				}
				if(inter2[j].open) {
					on++;
				} else on--;
			}
//			add++;
			ans += dist*add;
//			cout << dist << ". "<<add<<endl;
		}
		if(inter[i].open) visited[inter[i].pIn]=true;
		if(!inter[i].open) visited[inter[i].pIn]=false;

	}
	cout << ans << endl;
	// output

	return 0;
}
