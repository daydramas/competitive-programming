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
//struct edge {
//	int i, j, x, y; int weight;
//	edge(int i, int j, int x, int y, int weight) : i(i), j(j), x(x), y(y), weight(weight) {}
//};
//struct comp {
//  bool operator() (edge i,edge j) { return (i.weight<j.weight);}
//} comp;
//// global variables
//int A, B, N, M;
//vector<int> VA, HA;
//int pa[2010*2010];
//vector<edge> edges;
//// functions
//int get_ID(int i, int j) {return (i*(M+1))+j; }
//int calculateY(int i) {
//	if (i == 0) return VA[i];
//	return abs(VA[i]-VA[i-1]);
//}
//int calculateX(int i) {
//	if (i == 0) return HA[i];
//	return abs(HA[i]-HA[i-1]);
//}
//int find_parent(int x) {
//	if (x != pa[x]) pa[x] = find_parent(pa[x]);
//	return pa[x];
//}
//int main() {
//	// local variables
//
//	// input
//	cin >> A >> B >> N >> M;
//	for(int i=1; i<=N; i++) {int x; cin >> x; VA.push_back(x); }
//	VA.push_back(A);
//	for(int i=1; i<=M; i++) {int x; cin >> x; HA.push_back(x); }
//	HA.push_back(B);
//	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());
//	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) pa[get_ID(i,j)] = get_ID(i, j);
//	// main
////	for(int i=0; i<=N; i++) {
////		VA[i] = VA[i+1]-VA[i];
////	}
//	for(int i=0; i<=N; i++) {
//		for(int j=0; j<=M; j++) {
//			int x = i+1;
//			int y = j;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateX(j);
//				edges.push_back(edge(i,j,x,y,weight));
//			}
//			x--; y++;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateY(i);
//				edges.push_back(edge(i,j,x,y,weight));
//			}
//		}
//	}
//	sort(edges.begin(), edges.end(), comp);
//	long long ans = 0;
//	long long cnt = 0;
//	for(int k=0; k<edges.size(); k++) {
//		int i=edges[k].i, j=edges[k].j, x=edges[k].x, y=edges[k].y, w=edges[k].weight;
//		int X = find_parent(get_ID(i, j));
//		int Y = find_parent(get_ID(x, y));
//		if (X != Y) {
//			pa[X] = pa[Y] = pa[get_ID(i, j)] = pa[get_ID(x, y)] = X;
//			ans += w;
//			cnt++;
//		}
//		if(cnt == (N+1)*(M+1)) break;
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
struct edge {
	int i, j, x, y; int weight;
	edge(int i, int j, int x, int y, int weight) : i(i), j(j), x(x), y(y), weight(weight) {}
};
struct comp {
  bool operator() (edge i,edge j) { return (i.weight<j.weight);}
} comp;
// global variables
int A, B, N, M;
vector<int> VA, HA;
int pa[2010*2010];
vector<edge> edges;
// functions
int ID(int i, int j) {return (i*(M+1))+j; }
int calculateY(int i) {
	if (i == 0) return VA[i];
	return abs(VA[i]-VA[i-1]);
}
int calculateX(int i) {
	if (i == 0) return HA[i];
	return abs(HA[i]-HA[i-1]);
}
int find_parent(int x) {
	if (x != pa[x]) pa[x] = find_parent(pa[x]);
	return pa[x];
}
int merge(int x, int y) {
	int X = find_parent(y);
	int Y = find_parent(x);
	if(X == Y) return false;
	if (X != Y) {
		pa[X] = pa[Y] = pa[y] = pa[x] = X;
	}
	return true;

}
int main() {
	// local variables

	// input
	cin >> A >> B >> N >> M;
	VA.push_back(0); HA.push_back(0);
	for(int i=1; i<=N; i++) {int x; cin >> x; VA.push_back(x); }
	for(int i=1; i<=M; i++) {int x; cin >> x; HA.push_back(x); }
	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());
	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) pa[ID(i,j)] = ID(i, j);
	// main
	for(int i=0; i<N; i++) {
		VA[i] = VA[i+1]-VA[i];
	}
	VA[N] = B-VA[N];
	for(int i=0; i<M; i++) {
		HA[i] = HA[i+1]-HA[i];
	}
	HA[M] = A-HA[M];
	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());

	long long ans = 0;
	for(int vi=0, hi=0; vi<=N || hi<=M;) {
		if (hi==M+1 || (vi<=N and VA[vi]<HA[hi])) {
			for(int i=0; i+1<=M; i++) {
				if(merge(ID(vi, i), ID(vi, i+1))) {
					ans += VA[vi];
//					cout << VA[vi] << " <-" << endl;
				}
			}
			vi++;
		} else {
			for(int i=0; i+1<=N; i++) {
				if(merge(ID(i, hi), ID(i+1, hi))) {
					ans += HA[hi];
//					cout << HA[hi] << " <-" << endl;
				}
			}
			hi++;
		}
	}
	// output
	cout << ans << endl;
	return 0;
}
