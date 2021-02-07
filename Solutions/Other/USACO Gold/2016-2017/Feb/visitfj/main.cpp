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
#define BIG 1000000000
struct node {
	int x, y, time;
	node(int x, int y, int time) : x(x), y(y), time(time) {}
	bool operator<(node const& e) const {
		return time > e.time;
	}
};
// declare any global variables
int N, T, grass[110][110], dp[110][110], ans = BIG;
int X[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int Y[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
int sizeof_transition = 16;
// declare any functions
int distToFj(int i, int j) {return (N-i)+(N-j); }
int main() {

	// fstream
	ifstream fin ("visitfj.in");
	ofstream fout ("visitfj.out");

	// input
	fin >> N >> T;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) fin >> grass[i][j];
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) dp[i][j] = BIG;
	// main
	dp[1][1] = 0;
	priority_queue<node> q; q.push(node(1, 1, 0));
	while(!q.empty()){
		int x = q.top().x;
		int y = q.top().y;
		int time = q.top().time;
		q.pop();

//		cout << x << " " << y << " " << time << endl;

//		if(x==N and y==N) ans = min(ans, time);
		int d = distToFj(x, y);
		if(d < 3) ans = min(ans, time+(d*T));
		if(time > dp[x][y]) continue;

		for(int i=0; i<sizeof_transition; i++){
			int nx = x+X[i];
			int ny = y+Y[i];
			int nt = time+(3*T) + grass[nx][ny];
			if(nx >= 1 and nx <= N and ny >= 1 and ny <= N){
				if(nt < dp[nx][ny]){
					dp[nx][ny] = nt;
					q.push(node(nx, ny, nt));
				}
			}
		}
	}
	// output
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}
