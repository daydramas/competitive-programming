//#include <bits/stdc++.h>
//
//using namespace std;
//
//// defines
//#define ll long long
//#define pii pair<int, int>
//#define pll pair<ll, ll>
//#define f(i, a, b) for(ll i = a; i < b; i++)
//#define rf(i, a, b) for(ll i = a; i >= b; i--)
//#define w(a) while(a--)
//#define arrin(a,n) f(i,0,n) { cin >> a[i]; }
//#define arrin1(a,n) f(i,1,n+1) { cin >> a[i]; }
//#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
//#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
//ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }
//
//// structures
//
//// global variables
//
//// functions
//int main() {
//
//	// local variables
//
//	// input
//	fastio;
//
//	// main
//
//	// output
//
//	return 0;
//}
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
#define arrin1(a,n) f(i,1,n+1) { cin >> a[i]; }
#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }

// structures

// global variables

// functions
void solve() {
	int n; cin >> n;
	f(i,0,n) {
		int a; cin >> a; 
		if (i&1) {
			if (a < 0) a *= -1;
		} else {
			if (a > 0) a *= -1;
		}
		cout << a <<" ";
	}
	cout <<"\n";
}
int main() {

	// local variables

	// input
	fastio;
	int t; cin >> t;
	w(t) solve();
	// main

	// output

	return 0;
}
