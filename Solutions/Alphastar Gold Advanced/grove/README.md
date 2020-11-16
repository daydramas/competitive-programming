# grove
```cpp
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
//#define Pair pair<int, int>
//#define x first
//#define y second
//struct node {
//	int i, j, dist, dir; bool up, down, left, right, up1, down1, left1, right1;
//	node(int i, int j, int dist, int dir, bool u, bool d, bool l, bool r,bool u1, bool d1, bool l1, bool r1) : i(i), j(j), dist(dist), dir(dir), up(u), down(d), left(l), right(r), up1(u1), down1(d1), left1(l1), right1(r1) {}
//};
//// global variables
//int N, M;
//int grid[54][54], dist[54][54][2][2][2][2][2][2][2][2];
//Pair start, line;
//int minx, maxx, miny, maxy;
//int X[] = {1, 0, -1, 0, 1, -1, 1, -1};
//int Y[] = {0, 1, 0, -1, 1, -1, -1, 1};
//// functions
//
//int main() {
//	// local variables
//
//	// input
//	cin >> N >> M;
//	minx = miny = 1000000000;
//	maxx = maxy = 0;
//	for(int i=1; i<=N; i++) {
//		string grove; cin >> grove; grove = ' ' + grove;
//		for(int j=1; j<=M; j++) {
//			for(int k=0; k<2; k++)
//				for(int l=0; l<2; l++)
//					for(int n=0; n<2; n++)
//						for(int m=0; m<2; m++)
//							for(int k1=0; k1<2; k1++)
//								for(int l1=0; l1<2; l1++)
//									for(int n1=0; n1<2; n1++)
//										for(int m1=0; m1<2; m1++) dist[i][j][k][l][n][m][k1][l1][n1][m1] = 1000000000;
//			if(grove[j] == 'X') grid[i][j] = 0;
//			else if(grove[j] == '.') grid[i][j] = 1;
//			else if(grove[j] == '*') grid[i][j] = 1;
//			if(grove[j]=='*') start = Pair(i, j);
//			else if(grove[j]=='X') line = Pair(i, j);
//			if(grove[j] == 'X') {
////				cout << "hi" << endl;
//				minx = min(minx, i); miny=min(miny, j);
//				maxx = max(maxx, i); maxy=max(maxy, j);
//			}
//		}
//	}
//	// main
////	cout << minx << " "<<maxx<<" : " << miny << " " << maxy << endl;
////	for(int i=1; i<=N; i++) if(grid[i][line.y]==1) grid[i][line.y]=2;
////	for(int i=1; i<=M; i++) if(grid[line.x][i]==1) grid[line.x][i]=2;
//	queue<node> Q; Q.push(node(start.x, start.y, 0, 1, false, false, false, false, false, false, false, false)); dist[start.x][start.y][0][0][0][0][0][0][0][0]=0;
//	int ans = -1;
//	while(!Q.empty()) {
//		int i=Q.front().i, j=Q.front().j,dir=Q.front().dir, d=Q.front().dist;
//		bool up=Q.front().up, down=Q.front().down, left=Q.front().left, right=Q.front().right;
//		bool up1=Q.front().up1, down1=Q.front().down1, left1=Q.front().left1, right1=Q.front().right1;
//		Q.pop();
//		if(start.x==i && start.y==j && d!=0 && up && down && left && right && up1 && down1 && left1 && right1) {
//			ans=d; break;
//		}
//		if(d > dist[i][j][up][down][left][right][up1][down1][left1][right1]) continue;
////		if(start.x==i && start.y==j)
//			cout << i << " " << j << " : " << d<< " : "<<dist[i][j][up][down][left][right][up1][down1][left1][right1]<<" " << up<<down<<left<<right<<up1<<down1<<left1<<right1  << endl;
////		cout << i << " " << j << " : " << d << endl;
//		for(int k=0; k<8; k++) {
//			int x=i+X[k], y=j+Y[k], nd=d+1;
//			if(x>=1 && x<=N && y>=1 && y<=M && grid[x][y]!=0) {
//				bool u=up, d=down, l=left, r=right;
//				bool u1=up1, d1=down1, l1=left1, r1=right1;
//				if(x<=minx && y<=miny) u=true;
//				if(x>=minx && x<=maxx && y<=miny) d=true;
//				if(x>=maxx && y<=miny) l=true;
//				if(x<=minx && y>=maxy) r=true;
//				if(x>=minx && x<=maxx && y>=maxy) u1=true;
//				if(x>=maxx && y>=maxy) d1=true;
//				if(x<=minx && y>=miny && y<=maxx) l1=true;
//				if(x>=maxx && y>=miny && y<=maxx) r1=true;
//				cout << dist[x][y][u][d][l][r][u1][d1][l1][r1]<<" ; "<<nd<<endl;
//				if(nd<dist[x][y][u][d][l][r][u1][d1][l1][r1]) {
//					dist[x][y][u][d][l][r][u1][d1][l1][r1]=nd;
//					cout << x << ", " << y << endl;
//					Q.push(node(x,y,nd, k, u,d,l,r,u1,d1,l1,r1));
//				}
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

// global variables
int N, M;
int grid[54][54];
int dist[54][54][2];
int sx=-1, sy=-1, gx=-1, gy=-1;
int X[] = {1, 0, -1, 0, 1, -1, 1, -1};
int Y[] = {0, 1, 0, -1, 1, -1, -1, 1};
// functions
struct node {
	int i, j, d;
	node(int i, int j, int d) : i(i), j(j), d(d) {}
};
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		string str; cin >> str; str = ' ' + str;
		for(int j=1; j<=M; j++) {
			dist[i][j][0]=dist[i][j][1]=1000000000;
			if(str[j]=='X') {
				grid[i][j]=2;
//				if(gx==-1)
					gx=i, gy=j;
			}
			if(str[j]=='.' || str[j]=='*') {
				grid[i][j]=1;
				if(str[j]=='*') sx=i, sy=j;
			}
		}
	}
	dist[sx][sy][0]=0;
	queue<node>q;
    q.push(node(sx, sy, 0));
    while (!q.empty()) {
        node f = q.front();
        int p = dist[f.i][f.j][f.d];
        q.pop();
        for (int k=0; k<8; k++) {
            node go = node(f.i+X[k], f.j+Y[k], f.d);
            if (go.i<1 || go.i>N || go.j<1 || go.j>M){
            	continue;
            }
            if (grid[go.i][go.j] == 2) continue;
            if (f.i==gx-1 && go.i==gx && go.j<gy){
//            	cout << "2) "<<go.i<<" " << go.j<<endl;
            	continue;
            }
            if (f.i==gx && go.i==gx - 1 && go.j<gy) {
            	go.d++;
//            	cout << " hi  ...."<<endl;
                if (go.d > 1) continue;
            }
            if (p+1 < dist[go.i][go.j][go.d]) {
                dist[go.i][go.j][go.d] = p + 1;
                q.push(go);
            }
        }
    }
    cout << dist[sx][sy][1] << endl;
	// main

	// output

	return 0;
}

```