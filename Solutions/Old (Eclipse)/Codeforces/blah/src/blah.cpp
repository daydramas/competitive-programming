#include <bits/stdc++.h>
#include <math.h>

using namespace std;

//structures/defines
#define ll long long
#define pii pair<ll, int>
#define Yes() cout <<"Yes"<<endl;
#define No() cout <<"No"<<endl;
#define YES() cout <<"YES"<<endl;
#define NO() cout <<"NO"<<endl;

//global variables

//functions
bool comp(int a, int b) {
	return a > b;
}
void solve() {
	int n; int k;
	pii a[200005];
	ll b[200005];
	for (int i=0; i<n; i++) {
		cin >> b[i];
		a[i] = pii(b[i], i);
	}
	sort(a, a+n);
	for (int i=0; ; i++) {

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
