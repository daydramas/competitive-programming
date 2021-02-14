#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables

//functions
int getlb(int i) {
	for (int i1=30; i1>=0; i1--) {
		int temp = (1<<i1);
		if (i >= temp) return i1+1;
	}
	return 0;
}
void solve() {
	int d, m; cin >> d >> m;
	long long bit[32];
	bit[1] = 1; long long sum = 1%m;
	int lb = getlb(d);
	for (int i=2; i<lb; i++) {
		long long diff = (1<<i)-(1<<(i-1));
		bit[i] = ( diff + diff*sum ) % m;
		sum = ( sum+bit[i] ) % m;
//		cout<<(1<<i)<<" "<<(1<<(i-1)) <<" bit["<<i<<"] = "<<bit[i]<<endl;
	}
	long long diff = d-(1<<(lb-1))+1;
	sum = (sum + (diff)*(sum+1) ) % m;
	if (d == 1) cout <<(1%m)<<endl;
	else cout << sum << endl;
}
int main() {
	//local variables
	//input
	int t;
	cin >> t;
	for (int i=1; i<=t; i++) solve();

	//main

	//output

	return 0;
}
