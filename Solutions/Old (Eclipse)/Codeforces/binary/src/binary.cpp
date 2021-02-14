#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a!=0) for (int i=0; i<=a; i++) cout <<0;
	else if(b!=0) cout <<0;
	int t=1;
	bool flag = false;
	if (b%2 == 0) {
		flag = true;
	}
	for (int i=0; i<b-flag; i++) {
		cout <<t;
		t = 1-t;
	}
	for (int i=0; i<c; i++) cout <<1;
	if (b==0 && c) cout <<1;
//	if ((c==0&&b) || (b==0 && c)) cout <<1;
	if (flag && b) cout <<0;
//	if (b%2) cout <<0;
	cout << endl;

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
