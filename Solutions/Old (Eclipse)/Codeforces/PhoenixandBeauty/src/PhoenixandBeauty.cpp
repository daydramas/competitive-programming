#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, k; cin >> n >> k;
	int arr[105];
	vector<int> ans;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<k; i++) ans.push_back(arr[i]);
	int in = 0, in2 = k;
	while(in2 < n && in < in2) {
		ans.push_back(arr[in]);
		if (arr[in] == arr[in2]) {
			in = (in+1)%k;
			in2++;
		} else {
			in = (in+1)%k;
		}
		if (ans.size() > 10000) break;
	}
//	for (int i=k; i<n; i++) {
//		if (arr[i] != arr[in]) {
//			ans.push_back(arr[in]);
//			i--;
//		} else {
//			ans.push_back(arr[i]);
//		}
//		in = (in+1)%k;
//		if (ans.size() > 10000) {
//			break;
//		}
//	}
	if (ans.size() > 10000) {
		cout <<"-1"<<endl;
	} else {
		cout << ans.size() << endl;
		for (int i : ans) {
			cout << i << " ";
		}
		cout << endl;
	}
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
