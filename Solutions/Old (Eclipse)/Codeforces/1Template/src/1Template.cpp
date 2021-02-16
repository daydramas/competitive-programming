#include <bits/stdc++.h>
#include <math.h>

using namespace std;

//structures/defines
#define ll long long
#define Yes() cout <<"Yes"<<endl;
#define No() cout <<"No"<<endl;
#define YES() cout <<"YES"<<endl;
#define NO() cout <<"NO"<<endl;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
void primeFactors(ll n) {
    while (n % 2 == 0)  {
    	// 2 is factor
    	n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)  {
        while (n % i == 0)  {
        	// i is factor
            n = n/i;
        }
    }
    if (n > 2)  {
    	// n is factor
    }
}
//global variables
ll n, k, l;
ll t[200005], a[200005], b[200005];
ll ans = 1000000000000;

//functions

bool comp(ll a, ll b) {
	return a > b;
}
bool comp2(ll a, ll b) {
	return a < b;
}
void solve() {

}
void dfs(int i, ll a_, ll b_, ll c) {
	if (c >= ans) return;
	if (a_ >= k && b_ >= k) {
		ans = c; return;
	}
	if (i == n) return;
	dfs(i+1, a_+a[i], b_+b[i], c+t[i]);
	dfs(i+1, a_, b_, c);

}
int main() {
	//local variables

	//input
//	ll t; cin >> t;
//	for (int i=0; i<t; i++) solve();

	//main
	cin >> n >> l >> k;
	vector<ll> c, d;
	vector<ll> v;
	for (int i=0; i<n; i++) {
		cin >> t[i] >> a[i] >> b[i];

		if (a[i] && b[i]) {
			v.push_back(t[i]);
		} else if (a[i] && !b[i]) {
			c.push_back(t[i]);
		} else if (!a[i] && b[i]) {
			d.push_back(t[i]);
		}
	}
	sort(v.begin(), v.end());
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	int vi, ci, di; vi=ci=di=0;
	ll sum = 0;
	for (int i=0; i<l; i++) {
		if (v[vi] < c[ci] && v[vi] < d[di]) {
			sum += v[vi];
			vi++;
		} else if (v[vi] > c[ci] && c[ci] < d[di]) {
			sum += c[ci];
			ci++;
		} else {
			sum += d[di];
			di++;

		}
	}
	while(true) {
		int A = vi+ci;
		int B = vi+di;

		if (A >= k && B >= k) break;

		if (A < k && B <= k) {
			if (c[ci-1] > d[di-1]) {
				sum -= c[--ci];
			} else {
				sum -= d[--di];
			}
			sum += v[vi++];
		} else if (B < k && A <= k) {
			if (d[di-1] > c[ci-1]) {
				sum -= d[--di];
			} else {
				sum -= c[--ci];
			}
			sum += v[vi++];
		} else if (A < k && B > k) {
			if (v[vi] < c[ci]) {
				sum -= d[--di];
				sum += v[vi++];
			} else {
				sum -= d[--di];
				sum += c[ci++];
			}
		} else if (B < k && A > k) {
			if (v[vi] < d[di]) {
				sum -= c[--ci];
				sum += v[vi++];
			} else {
				sum -= c[--ci];
				sum += d[di++];
			}
		}
	}
	cout << sum << endl;
	return 0;
}