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
//
//// structures / defines
//
////Data Structures
//
//struct point { int x, y; char c; };
//struct line { struct point p1, p2; };
//struct point polygon[1004];
//
////Testing whether line segments intersect
//
//int ccw(struct point p0, struct point p1, struct point p2)
//{
//	int dx1, dx2, dy1, dy2;
//	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
//	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
//	if(dx1*dy2 > dy1*dx2) return +1;
//	if(dx1*dy2 < dy1*dx2) return -1;
//	if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
//	if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return +1;
//	return 0;
//}
//
//int intersect(struct line l1, struct line l2)
//{
//	return ((ccw(l1.p1, l1.p2, l2.p1)
//	        *ccw(l1.p1, l1.p2, l2.p2)) <= 0)
//	    && ((ccw(l2.p1, l2.p2, l1.p1)
//	        *ccw(l2.p1, l2.p2, l1.p2)) <= 0);
//}
//
////Testing whether a point is in a polygon
//
//int inside(struct point t, point p[1004], int N)
//{
//	int i, count = 0, j = 0;
//	struct line lt,lp;
//	p[0] = p[N]; p[N+1] = p[1];
//	lt.p1 = t; lt.p2 = t; lt.p2.x = 1000000000;
//	for(i=1; i<=N; i++) {
//		lp.p1 = p[i]; lp.p2 = p[i];
//		if(!intersect(lp,lt)) {
//			lp.p2 = p[j]; j = i;
//			if (intersect(lp,lt)) count++;
//		}
//	}
//	return count & 1;
//}
//
//struct node {
//	bool visited; int parent;
//};
//
//// global variables
//
//int N, C;
//struct line fence[1004];
//struct point cow[1004];
//struct node nodes[1004];
//struct point cycle[1004][1004]; int cycles[1004];
//int ans = 0;
//
//// functions
//void findCycle(int fenceIn, int parent, point finder) {
//	nodes[fenceIn].visited = true;
//	for(int i=1; i<=N; i++) {
//		if(!nodes[i].visited) {
//			if (finder.x == fence[i].p1.x && finder.y == fence[i].p1.y) {
//				nodes[i].parent = parent;
//				cycle[parent][++cycles[parent]] = fence[i].p2;
//				findCycle(i, parent, fence[i].p2);
//				break;
//			} else if (finder.x == fence[i].p2.x && finder.y == fence[i].p2.y) {
//				nodes[i].parent = parent;
//				cycle[parent][++cycles[parent]] = fence[i].p1;
//				findCycle(i, parent, fence[i].p1);
//				break;
//			}
//
//		}
//	}
//}
//void solve(int i) {
//	for(int i1=0; i1<=N+1; i1++) cycle[i][i1].x = -1, cycle[i][i1].y = -1;
//	cycles[i] = 0; cycle[i][++cycles[i]] = fence[i].p2;
//	findCycle(i, i, fence[i].p2);
//
////	cout << "cycle: ";
////	for(int i1=1; i1<=N; i1++) {
////		if(cycle[i][i1].x == -1) break;
////		cout <<"("<< cycle[i][i1].x << ", " << cycle[i][i1].y<<") ";
////	}
////	cout << endl;
//}
//int main() {
//	// local variables
//
//	// input
//	cin >> N >> C;
//	for(int i=1; i<=N; i++) {
//		cin >> fence[i].p1.x >> fence[i].p1.y;
//		cin >> fence[i].p2.x >> fence[i].p2.y;
//		nodes[i].visited = false, nodes[i].parent = i;
//	}
//	for(int i=1; i<=C; i++) {
//		cin >> cow[i].x >> cow[i].y;
//	}
//
//	// main
//	int numOfCycles = 0;
//	for(int i=1; i<=N; i++) {
//		if(!nodes[i].visited) {
//			numOfCycles++;
////			cout << "New cycle begins solving here!"<<endl;
//			solve(i);
//		}
//	}
//	for(int i=1; i<=numOfCycles; i++) {
//		int tempAns = 0;
//		for(int i1=1; i1<=C; i1++) {
//			bool inTheFence = (inside(cow[i1], cycle[i], cycles[i])%2) == 1;
//			if(inTheFence) {
//				bool add = true;
//				for(int j=1; j<=numOfCycles; j++) {
//					if(j==i) continue;
//					bool inTheFence2 = (inside(cow[i1], cycle[j], cycles[j])%2) == 1;
//					if (inTheFence2) {
//						bool inTheFence3 = (inside(cycle[i][1], cycle[j], cycles[j])%2) == 1;
//						if(!inTheFence3) add = false; break;
//					}
//				}
//				if (add) tempAns++;
//			}
//		}
//		ans = max(ans, tempAns);
//	}
//	// output
//	cout << ans << endl;
//	return 0;
//}
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
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define N_MAX 1004
#define C_MAX 1004

bool numOfRayHits(long long cx, long long cy, long long f1x, long long f1y, long long f2x, long long f2y) {
    if ((f1y > cy) ^ (f2y > cy)) {
        return (f1y - f2y < 0) ^ (f2x * (f1y - cy) + f1x * (cy - f2y) > cx * (f1y - f2y));
    } else {
        return false;
    }
}

map<pair<int,int>, vector<int> > pointMap;
pair<pair<int,int>, pair<int,int> > fences[N_MAX];
int cycle[N_MAX];

char parities[C_MAX][N_MAX];

char* parityptrs[C_MAX];
inline bool comparee(char* a, char* b) {
    return strcmp(a, b) < 0;
}

int main() {

    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        pair<int,int> p1, p2;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        pointMap[p1].push_back(i);
        pointMap[p2].push_back(i);
        fences[i] = pair<pair<int,int>, pair<int,int> >(p1, p2);
        cycle[i] = -1;
        memset(parities[i], 0, C);
    }
    for (int i = 0; i < C; i++) {
        parityptrs[i] = parities[i];
    }

    int nCycles = 0;
    for (int i = 0; i < N; i++) {
        if (cycle[i] == -1) {
            int j = i;
            pair<int,int> last = fences[i].first;
            do {
                cycle[j] = nCycles;
                last = fences[j].first == last ? fences[j].second : fences[j].first;
                vector<int> const& v = pointMap[last];
                j = (v[0] == j ? v[1] : v[0]);
            } while (j != i);
            nCycles++;
        }
    }

    for (int i = 0; i < C; i++) {
        int cowx, cowy;
        cin >> cowx >> cowy;
        for (int j = 0; j < N; j++) {
            parities[i][cycle[j]] ^= (char)numOfRayHits(cowx, cowy, fences[j].first.first, fences[j].first.second, fences[j].second.first, fences[j].second.second);
        }
        for (int j = 0; j < nCycles; j++) {
            parities[i][j] = parities[i][j] ? '1' : '0';
        }
        parities[i][nCycles] = '\0';
    }

    sort(parityptrs, parityptrs + C, comparee);

    int maxans = 0;
    int curcount = 0;
    for (int i = 0; i < C; i++) {
        if (i == 0 || strcmp(parityptrs[i], parityptrs[i-1]) != 0) {
            curcount = 1;
        } else {
            curcount++;
        }
        maxans = max(maxans, curcount);
    }
    cout << maxans << endl;
}
