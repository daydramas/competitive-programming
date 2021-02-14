#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define pii pair<int, int>

//global variables
pii m[2005];
//functions

int main() {
	//local variables

	//input
	int n, k; cin >> n >> k;
	string board[2005];
	string num[12] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	for (int i=1; i<=n; i++) cin >> board[i];

	//main
	int sm = 0;
	for (int i=1; i<=n; i++) {
		int mm = 100, mn = -1;
		for (int j=0; j<=9; j++) {
			bool ok = true;
			int tmp = 0;
			for (int k1=0; k1<7; k1++) {
				if (board[i][k1]=='1' && num[j][k1]=='0') ok = false;
				if (board[i][k1]=='0' && num[j][k1]=='1') tmp++;
			}
			if (ok) {
				if (tmp < mm) {
					mm = tmp;
					mn = j;
				} else if (tmp == mm && mn < j) {
					mn = j;
				}
			}
		}
		sm += mm;
//		cout << mm <<" " << mn << endl;
		m[i] = pii(mm, mn);
	}
	if (sm <= k) {
		for (int i=1; i<=n; i++) {
			int tans = -1;
			for (int j=9; j>=0; j--) {
				bool ok = true;
				int tmp = 0;
				for (int k1=0; k1<7; k1++) {
					if (board[i][k1]=='1' && num[j][k1]=='0') ok = false;
					if (board[i][k1]=='0' && num[j][k1]=='1') tmp++;
				}
				if (ok && (k-sm+m[i].first-tmp)) {
					tans = j;
					k += -sm+m[i].first-tmp;
					break;
				}
			}
			cout << tans;
		}cout << endl;
	} else {
		cout << "-1"<<endl;
	}
	//output

	return 0;
}
