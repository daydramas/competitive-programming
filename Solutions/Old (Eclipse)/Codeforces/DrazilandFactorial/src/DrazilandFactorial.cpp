#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int n; string a;
int fact[10];
int prime[4] = {2, 3, 5, 7};
int cnt[4] = {0, 0, 0, 0};
//functions
int toIN(int p) {
	for (int i=0; i<4; i++) {
		if (p == prime[i]) return i;
	}
	return -1;
}
int main() {
	//local variables
	//input
	cin >> n >> a;
	//main
//	cout << "a: "<<a<<endl;
	for (int i=0; i<n; i++) {
		int val = a[i]-'0';
//		cout << val << endl;
		if (val == 9) {
			cnt[3]++;
			cnt[1]+=2;
			cnt[0]++;
		} else if (val == 8) {
			cnt[3]++;
			cnt[0]+=3;
//			cout << val << " adding 7"<<endl;
		} else if (val == 6) {
			cnt[2]++;
			cnt[1]++;
		} else if (val == 4) {
			cnt[1]++;
			cnt[0]+=2;
		} else if (val == 7) {
			cnt[3]++;
//			cout<<val << " adding 7"<<endl;
		} else if (val == 5) {
			cnt[2]++;
		} else if (val == 3) {
			cnt[1]++;
		} else if (val == 2) {
			cnt[0]++;
		}
//		a /= 10;
	}
	//output
//	for (int i=0; i<4; i++) {
//		cout <<prime[i]<<": "<<cnt[i]<<endl;
//	}
	for (int i=3; i>=0; i--) {
		for (int j=1; j<=cnt[i]; j++) {
			cout <<prime[i];
		}
	}
	cout << endl;
	return 0;
}
