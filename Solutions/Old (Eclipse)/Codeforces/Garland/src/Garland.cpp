#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
//	int a; cin >> a;
	int n1 = 0;
//	while(str[str.size()-1] == '0') {
//		str.pop_back();
//	}
//	n = str.size();
	for (int i = 0; i < n; i++)
		if (str[i] == '1')
			n1++;
	ll ans = 10000000000;
	for (int j = 0; j < k; j++) {
		int T0, T, T2;
		T0 = T = T2 = 0;

		for (int i = j; i < n; i = i + k) {

			//		cout << T0[i%k] <<endl;

			if (str[i] == '0')
				T0++;

			//		if (str[i]=='0' && T2[i%k]) T[i%k]++;

			if (str[i] == '1') {

				//			T2[i%k]++;

				if (T2 == 0) {

				} else {

					T += T0;

				}
				T2++;
				T0 = 0;

			}

		}

		ans = min(ans, (long long) T + (n1 - T2));

	}
	cout << ans << endl;

}
int main() {
	//local variables

	//input
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
	//main

	//output

	return 0;
}
