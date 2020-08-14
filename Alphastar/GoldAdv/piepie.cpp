//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//using namespace std;
//// structures / defines
//struct node {
//	int i, j; long long weight;
//	node(int i, int j, long long weight) : i(i), j(j), weight(weight) {}
//};
//struct abc {
//	int i, j; long long dist;
//	abc(int i, int j, long long dist) : i(i), j(j), dist(dist) {}
//};
//struct comp {
//	bool operator() (abc a, abc b) const {
//		return a.dist<b.dist;
//	}
//};
//// global variables
//#define Pair pair<int, int>
//int A, B, N, M;
//vector<long long> VA, HA;
//map<int, vector<node> > edge[2010];
//map<int, bool> visited[2010];
//map<int, int> dist[2010];
//// functions
//long long calculateY(int i) {
//	if (i == 0) return VA[i];
//	return abs(VA[i]-VA[i-1]);
//}
//long long calculateX(int i) {
//	if (i == 0) return HA[i];
//	return abs(HA[i]-HA[i-1]);
//}
//int main() {
//	// local variables
//
//	// input
//	cin >> A >> B >> N >> M;
//	for(int i=1; i<=N; i++) { int x; cin >> x; VA.push_back(x); }
//	VA.push_back(A);
//	for(int i=1; i<=M; i++) { int x; cin >> x; HA.push_back(x); }
//	HA.push_back(B);
//	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());
//	// main
//	// create graph
//	for(int i=0; i<=N; i++) {
//		for(int j=0; j<=M; j++) {
//			visited[i][j] = false;
//			int x = i+1;
//			int y = j;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateX(j);
//				edge[i][j].push_back(node(x, y, weight));
//				edge[x][y].push_back(node(i, j, weight));
//			}
//			x--; y++;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateY(i);
//				edge[i][j].push_back(node(x, y, weight));
//				edge[x][y].push_back(node(i, j, weight));
//			}
//		}
//	}
//	// mst
//	int msted = 0;
//	long long ans = 0;
//	multiset<abc, comp> Q;
//	Q.insert(abc(0, 0, 0));
//	while(!Q.empty()) {
//		abc f = *Q.begin();
//		Q.erase(Q.begin());
////		cout << f.dist <<" < - "<< f.i << " " << f.j << endl;
//		if(visited[f.i][f.j]) continue;
//		ans += f.dist;
//		visited[f.i][f.j] = true; msted++;
//		if(msted == (N+1)*(M+1)) {
////			cout << msted << endl;
//			break;
//		}
//
//		for(int i=0; i<edge[f.i][f.j].size(); i++) {
//			int x=edge[f.i][f.j][i].i;
//			int y=edge[f.i][f.j][i].j;
//			if(!visited[x][y]){
//				Q.insert(abc(x,y,edge[f.i][f.j][i].weight));
//			}
//		}
//	}
//	// output
//	cout << ans << endl;
//	return 0;
//}
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
	int i, j; long long weight;
	node(int i, int j, long long weight) : i(i), j(j), weight(weight) {}
};
struct abc {
	int i, j; long long dist;
	abc(int i, int j, long long dist) : i(i), j(j), dist(dist) {}
};
struct comp {
	bool operator() (abc const&a, abc const&b){
		return a.dist>b.dist;
	}
};
struct s2b2 {
  bool operator() (int i,int j) { return (i<j);}
} s2b;
// global variables
#define Pair pair<int, int>
long long A, B; int N, M;
vector<int> VA, HA;
bool visited[2010*2010];
// functions
long long calculateY(int i) {
	if (i == 0) return VA[i];
	return abs(VA[i]-VA[i-1]);
}
long long calculateX(int i) {
	if (i == 0) return HA[i];
	return abs(HA[i]-HA[i-1]);
}
bool valid(int i, int j) {
	return (i>=0 and i<=N and j>=0 and j<=M);
}
int v(int i, int j) {
	return (i*(N+1))+j;
}
int main() {
	// local variables

	// input
	cin >> A >> B >> N >> M;
	for(int i=1; i<=N; i++) { int x; cin >> x; VA.push_back(x); }
	VA.push_back(A);
	for(int i=1; i<=M; i++) { int x; cin >> x; HA.push_back(x); }
	HA.push_back(B);
	for(int i=0; i<=N; i++) {
		for(int j=0; j<=M; j++) {
			visited[v(i, j)] = false;
		}
	}
	sort(VA.begin(), VA.end(), s2b);
	sort(HA.begin(), HA.end(), s2b);
	// main
	int msted = 0;
	long long ans = 0;
	priority_queue<abc, vector<abc>, comp> Q;
	Q.push(abc(0, 0, 0));
	while(!Q.empty()) {
		abc f = Q.top();
		Q.pop();
		if(visited[v(f.i,f.j)]) continue;
		ans += (long long) f.dist;
		visited[v(f.i,f.j)] = true; msted++;
		if(msted == (N+1)*(M+1)) {
			break;
		}
		int x, y;

		x=f.i+1, y=f.j;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateX(y);
			Q.push(abc(x,y,weight));
		}

		x=f.i, y=f.j+1;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateY(x);
			Q.push(abc(x,y,weight));
		}

		x=f.i-1, y=f.j;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateX(y);
			Q.push(abc(x,y,weight));
		}

		x=f.i, y=f.j-1;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateY(x);
			Q.push(abc(x,y,weight));
		}
	}
	// output
	cout << ans << endl;
	return 0;
}
