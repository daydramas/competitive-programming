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
struct node {
	int i, j, dist;
	node(int i, int j, int dist) : i(i), j(j), dist(dist) {}
};
struct comp{
    bool operator()(const node& a, const node& b) {
    	return a.dist>b.dist;
    }
};
// global variables
int N, A, B;
bool pasture[44][44], visited[44][44];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
long long ans = 0;
// functions
int distance(int i, int j, int x, int y) {
	if(pasture[i][j] == pasture[x][y]) return A;
	return B;
}
void shortestPath(int si, int sj) {
	priority_queue<node, vector<node>, comp> Q;
	Q.push(node(si, sj, 0));
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) visited[i][j]=false;
	while(!Q.empty()) {
		int i=Q.top().i, j=Q.top().j, dist=Q.top().dist;
		Q.pop();
		if(visited[i][j]) continue;
		ans = max(ans, (long long) dist);
		visited[i][j]=true;
		for(int k=0; k<4; k++) {
			int x=i+X[k], y=j+Y[k];
			if(x>=1 and x<=N and y>=1 and y<=N) {
				if(!visited[x][y]) {
					int ndist = dist+distance(i, j, x, y);
					Q.push(node(x,y,ndist));
				}
			}
		}
	}
}
int main() {
	// local variables

	// input
	cin >> N >> A >> B;
	for(int i=1; i<=N; i++) {
		string read; cin >> read;
		for(int j=1; j<=N; j++) {
			if(read[j-1] == '(') pasture[i][j] = true;
			if(read[j-1] == ')') pasture[i][j] = false;
		}
	}
	// main
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			shortestPath(i,j);
		}
	}
	cout <<ans << endl;
	// output

	return 0;
}
