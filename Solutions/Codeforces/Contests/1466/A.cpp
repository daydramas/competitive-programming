#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		static int n;
		static int a[55];
		cin >> n;
		set<int> p;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				p.insert(abs(a[j] - a[i]));
			}
		cout << p.size() << '\n';
		
	}	
}