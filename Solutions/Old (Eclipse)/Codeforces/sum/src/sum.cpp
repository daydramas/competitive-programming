#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	string n; cin >> n;
	vector<string> ans;
	for (int i=0; i<n.length(); i++) {
		if (n[i] == '0') continue;
		string tmp = string(1, n[i]);
//		cout << "tmp: "<<tmp<<endl;
		for (int i2=i+1; i2<n.length(); i2++)tmp+="0";
		ans.push_back(tmp);
	}
	cout << ans.size() << endl;
	for (string i : ans) cout << i <<" ";
	cout << endl;
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) {
		solve();
	}
	//main

	//output

	return 0;
}
