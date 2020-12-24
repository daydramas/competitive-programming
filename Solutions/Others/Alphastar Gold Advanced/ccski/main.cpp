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
#define Pair pair<int, int>
#define mp make_pair
#define a first
#define b second

// global variables
int N, M;
int wx=1, wy=1;
int elevation[501][501];
bool wayPoint[501][501];
bool visited[501][501];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
// functions
void bfs(int D) {
	queue<Pair> q;
	q.push(mp(wx, wy));
	visited[wx][wy] = true;
	while(!q.empty()) {
		Pair p=q.front();
		for(int i=0; i<4; i++) {
			int x=p.a+X[i];
			int y=p.b+Y[i];
			if(x>=1 and x<=N and y>=1 and y<=M and !visited[x][y] and abs(elevation[p.a][p.b]-elevation[x][y])<=D) {
				visited[x][y]=true;
				q.push(mp(x, y));
			}
		}
		q.pop();
	}
}
bool if_reachable(int D) {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			visited[i][j]=false;
		}
	}
	bfs(D);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(wayPoint[i][j] && !visited[i][j]) return false;
		}
	}
	return true;
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin >> elevation[i][j];
		}
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			int read; cin >> read;
			if(read == 1){
				wayPoint[i][j] = true;
				wx=i; wy=j;
			}
			else wayPoint[i][j] = false;
		}
	}

	// main
	int small = 0, big = 1000000000;
	while(small < big) {
		int mid = (small+big)/2;
		if(if_reachable(mid)) {
			big = mid;
//			cout <<"reachable "<<mid<<endl;
		} else{
//			cout <<"unreachable "<<mid<<endl;
			small=mid+1;
		}
	}
	// output
	cout << small <<endl;
	return 0;
}
