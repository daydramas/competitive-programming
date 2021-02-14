#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
#define Yes() cout <<"Yes"<<endl;
#define No() cout <<"No"<<endl;
#define YES() cout <<"YES"<<endl;
#define NO() cout <<"NO"<<endl;

//global variables

//functions

void solve() {
	int n; cin >> n;
	int num = 4 + n*3;
	cout << num << endl;
	cout << "0 0"<<endl;
	cout << "1 0"<<endl;
	cout << "0 1"<<endl;
	cout <<"1 1"<<endl;
	for (int i=1; i<=n; i++) {
		cout << i <<" "<<i+1<<endl;
		cout <<i+1<<" "<<i<<endl;
		cout << i+1 <<" "<<i+1<<endl;
	}
}
int main() {
	//local variables

	//input
	int t;
//	cin >> t;
	t = 1;
	for (int i=0; i<t; i++) solve();

	//main

	//output

	return 0;
}
