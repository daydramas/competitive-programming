/**
 * cowsignal
*/

#include <iostream>
#include <string>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	static int m, n, k;
	string s;

	cin >> m >> n >> k;
	for(int i=0; i<m; i++) {
		cin >> s;
		for(int kk=0; kk<k; kk++) {
			for(char c : s) 
			for(int j=0; j<k; j++) 
				cout << c;
			cout << '\n';
		}

	}
}