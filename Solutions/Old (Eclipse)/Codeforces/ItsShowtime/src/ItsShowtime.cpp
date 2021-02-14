#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int in, N, M;

//functions

int main() {
	//local variables

	//input
	cin >> in;
	N = in/1000;
	M = in%1000;

	//main
	int ans = 1;
	for (int i=N; i>=1; i-=2) {
		ans = (ans*i) % M;
	}
	//output
	cout << ans << endl;
	return 0;
}
