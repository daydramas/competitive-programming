#include <bits/stdc++.h>

using namespace std;

// defines
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f(i, a, b) for(ll i = a; i < b; i++)
#define rf(i, a, b) for(ll i = a; i >= b; i--)
#define w(a) while(a--)
#define arrin(a,n) f(i,0,n) { cin >> a[i]; }
#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }

// structures

// global variables
int n;
ll w[700000];

// functions

int main() {

	// local variables

	// input
	fastio;
	cin >> n; arrin(w, n);

	// main
	ll a, b; a=b=0;
	rf(i, n-1, 0) if (b+w[i] >= a) {
		b += w[i];
		swap(a, b);
	}

	// output
	cout << a << " " << b << endl;
	return 0;
}
