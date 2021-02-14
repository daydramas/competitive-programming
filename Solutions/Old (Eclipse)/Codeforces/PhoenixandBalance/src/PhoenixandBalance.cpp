#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n; cin >> n;
	long long sum1 = (1<<n); int i1 = 1;
	long long sum2 = (1<<(n-1)); int i2 = n-2;
	for (int i=1; i<n/2; i++) {
		sum1 += (1<<i1);
		sum2 += (1<<i2);
		i1++; i2--;
	}
	cout << (sum1-sum2) << endl;
//	cout << sum1 <<" " << sum2 << endl;
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) solve();

	//main

	//output

	return 0;
}
