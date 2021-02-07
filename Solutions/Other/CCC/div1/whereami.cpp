/**
 * whereami
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	static int n;
	string s, t;

	cin >> n >> s;
	int i;
	for(i=1; i<=n; i++) {
		bool flag = true;
		set<string> os;
		for(int j=0; j+i<=n; j++) {
			t = s.substr(j, i);
			if(os.find(t) != os.end()) {
				flag = false;
				break;
			} else os.insert(t);
		}
		if(flag) break;
	}
	cout << i << '\n';
}