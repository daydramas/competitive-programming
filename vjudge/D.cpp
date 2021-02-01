/**
 * D - 类似合并果子
*/

#include <iostream>
#include <queue>
using namespace std;

#define N	(1<<18) // 2e5
#define ll long long

int main() {

	static int n; static ll x;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		pq.push(x);
	}
	
	static ll a, b, ans = 0;
	for(int i=1; i<n; i++) {
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		ans += a+b;
		pq.push(a+b);
	}
	cout << ans << '\n';
}