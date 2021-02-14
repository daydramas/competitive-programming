#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
#define pii pair<int, int>

//global variables
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
//functions
void solve() {
	int n, m;
	cin >> n >> m; int cnt = 0;
	string maze[51];
	bool visited[51][51];
	for (int i=0; i<n; i++) cin>>maze[i];

	for (int i=0; i<n; i++)
	for (int j=0; j<m; j++) {
		if (maze[i][j]=='B') {
			for (int k=0; k<4; k++) {
				int x = i+X[k], y=j+Y[k];
				if (x>=0 && y>=0 && x<n && y<m) {
					if (maze[x][y]=='G') {
						cout <<"No"<<endl;
						return;
					} else if (maze[x][y]!='B') maze[x][y]='#';
				}
			}
		}
		if (maze[i][j]=='G') {
			cnt++;
		}
		visited[i][j] = false;
	}

	if (maze[n-1][m-1]=='#') {
		if (cnt) cout <<"No"<<endl;
		else cout <<"Yes"<<endl;
		return;
	}
	queue<pii>Q;
	Q.push(pii(n-1, m-1));
	visited[n-1][m-1] = true;
	while(!Q.empty()) {
		int i=Q.front().first, j=Q.front().second; Q.pop();
//		cout <<i<<" "<<j<<endl;
//		cout << maze[i][j]<<endl;
		if (maze[i][j]=='G') cnt--;

		for (int k=0; k<4; k++) {
			int x = i+X[k], y=j+Y[k];
			if (x>=0 && y>=0 && x<n && y<m) {

				if (!visited[x][y] && maze[x][y]!='#') {
					Q.push(pii(x, y));
					visited[x][y] = true;
				}
			}
		}
	}
	if (cnt==0) {
		cout <<"Yes"<<endl;
	} else cout <<"No"<<endl;

}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=0; i<t; i++) solve();

	//main

	//output

	return 0;
}
