/**
 * cowsum
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

struct cow {
	int att[4], st, en;
};

template<class T> bool ckmax(T &a, const T &b) {
	return (b > a ? a = b, 1 : 0);
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	freopen("cowsum.in", "r", stdin);
	freopen("cowsum.out", "w", stdout);

	static int n, t;
	cow res, x;

	for(int i=0; i<4; i++) res.att[i] = -1;

	cin >> n >> t;
	for(int i=0; i<n; i++) {
		for(int k=0; k<4; k++) {
			cin >> x.att[k];
		}
		cin >> x.st >> x.en;
		if(x.st <= t && x.en >= t) {
			for(int k=0; k<4; k++) {
				ckmax(res.att[k], x.att[k]);
			}
		}
	}
	for(int k=0; k<4; k++) {
		cout << res.att[k] << '\n';
	}
}