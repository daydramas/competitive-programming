#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int t;
int a,b,c,d;
int x,y,x1,y3,x2,y2;
bool ans;


//functions
void dfs(int i, int j, int a1, int b1, int c1, int d1) {
	if (i < x1 || y < y3 || i > x2 || j > y2) return;
//	cout << i <<" " << j<<" " << a1 <<b1<<c1<<d1<<endl;
	if (a1 && b1 && c1 && d1) {
		ans = true;
		return;
	}
	if (!a1) dfs(i-a, j, 1, b1, c1, d1);
	if (!b1) dfs(i+b, j, a1, 1, c1, d1);
	if (!c1) dfs(i, j-c, a1, b1, 1, d1);
	if (!d1) dfs(i, j+d, a1, b1, c1, 1);
}
int main() {
	//local variables

	//input
	cin >> t;
	for (int i=1; i<=t; i++) {
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y3 >> x2 >> y2;
//		ans = false; dfs(x, y, 0, 0, 0, 0);
		ans = x1 <= (x-a+b) && (x-a+b) <= x2 && y3 <= (y-c+d) && (y-c+d) <= y2;
		cout << (ans?"Yes":"No") << endl;
	}
	//main

	//output

	return 0;
}
