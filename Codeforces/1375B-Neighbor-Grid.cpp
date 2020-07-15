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
	int n, m; int g[300][300]; int a[300][300];
	cin >> n >> m;
	f(i,0,n) f(j,0,m) {
		cin >> g[i][j];
		a[i][j] = 4;
	}
	f(i,0,n) a[i][0] = a[i][m-1] = 3;
	f(i,0,m) a[0][i] = a[n-1][i] = 3;
	a[0][0] = a[0][m-1] = a[n-1][0] = a[n-1][m-1] = 2;
	f(i,0,n) f(j,0,m) {
		if (g[i][j] > a[i][j]) {
			cout <<"NO"<<endl;
			return;
		}
	}
	cout <<"YES"<<endl;
	f(i,0,n)  {
		f(j,0,m) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}

}
int main() {

	// local variables

	// input
	fastio;
	int t; cin >> t;

	// main
  	w(t) solve();

	// output

	return 0;
}
