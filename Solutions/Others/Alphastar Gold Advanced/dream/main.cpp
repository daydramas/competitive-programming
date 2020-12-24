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
	int i; int j; int moves; int direction; bool orange;
	node(int i, int j, int moves, int direction, bool orange) : i(i), j(j), moves(moves), direction(direction), orange(orange) {}
};
struct nNode {
	int i; int j; int direction; bool orange;
	nNode(int i, int j, int direction, bool orange) : i(i), j(j), direction(direction), orange(orange) {}
};
// global variables
int N, M;
int maze[1004][1004];
int dist[1004][1004];
//map<nNode, bool> visited;
bool visited[1004][1004][4][2];
int ans = -1;
int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};
// functions
bool valid(int i, int j) {
	return (i>=1 && i<=N && j>=1 && j<=M);
}
void bfs() {
	queue<node> Q; Q.push(node(1,1,0,3,false));
	dist[1][1]=0;
	while(!Q.empty()) {
		int i=Q.front().i, j=Q.front().j, moves=Q.front().moves, direction=Q.front().direction;
		bool orange=Q.front().orange; Q.pop();
		if(visited[i][j][direction][(int)orange]) continue;
		visited[i][j][direction][(int)orange] = true;
//		cout << i << " " << j << " : " << moves << endl;
		if(i==N && j==M) {
			ans = moves;
			return;
		}
		if(maze[i][j] == 4) {
			int x=i+X[direction],y=j+Y[direction];
			if(!valid(x,y) || maze[x][y]==0 || (maze[x][y]==3 && !orange)) {

				for(int k=0; k<4; k++) {
					if(direction == k) continue;
					int x1=i+X[k], y1=j+Y[k];
					if(valid(x1, y1) && maze[x1][y1]!=0){
						if(maze[x1][y1]==3 && !orange) continue;
						bool nOrange = orange;
						if(maze[x1][y1]==2) nOrange=true;
						if(maze[x1][y1]==4) nOrange=false;
						if(visited[x1][y1][k][(int)nOrange]) continue;
						dist[x1][y1]=moves+1;
						Q.push(node(x1,y1,moves+1,k,nOrange));
					}
				}
			} else if (maze[x][y]!=0){
				Q.push(node(x,y,moves+1, direction,false));
				dist[x][y]=moves+1;
			}
		} else {
			for(int k=0; k<4; k++) {
				int x1=i+X[k], y1=j+Y[k];
				if(valid(x1, y1) && maze[x1][y1]!=0){
					if(maze[x1][y1]==3 && !orange) continue;
					bool nOrange = orange;
					if(maze[x1][y1]==2) nOrange=true;
					if(maze[x1][y1]==4) nOrange=false;
					if(visited[x1][y1][k][(int)nOrange]) continue;
					dist[x1][y1]=moves+1;
					Q.push(node(x1,y1,moves+1,k,nOrange));
				}
			}
		}
	}
}
int main() {
	// local variables
	ifstream fin("dream.in");
	ofstream fout("dream.out");
	// input
	fin >> N >> M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			fin >> maze[i][j];
			dist[i][j] = -1;
			for(int k=0; k<4; k++) {
				visited[i][j][k][0]=visited[i][j][k][1]=false;
			}
		}
	}
	// main
	bfs();
	// output
	fout << ans << endl;
	return 0;
}
