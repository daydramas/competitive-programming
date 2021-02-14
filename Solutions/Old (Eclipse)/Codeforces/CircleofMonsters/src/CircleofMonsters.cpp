//#include <bits/stdc++.h>
//
//using namespace std;
//
////structures/defines
//#define ll long long
//#define pii pair<ll, ll>
//
////global variables
//
////functions
//void solve() {
//	ll n, a[300000], b[300000]; cin >> n;
//	for (int i=0; i<n; i++) cin >> a[i] >> b[i];
//	ll s = -1; ll ss = 10000000000000;
//	ll sum = 0, omin = 10000000000000, oin = -1;
//	for (int i=0; i<n; i++) {
//		int prev = (i-1+n)%n;
//		ll dif = b[prev]-a[i];
////		cout << dif << endl;
//		if (omin > a[i]) {
//			omin = a[i];
//			oin = i;
//		}
//		if (dif >= 0) {
//			if (ss > a[i]){
//				s = i;
//				ss = a[i];
//			}
//		} else {
//			sum -= dif;
//		}
//	}
//	if (s == -1) {
//		sum += b[(oin-1+n)%n];
//	} else {
//		sum += ss;
//	}
//	cout << sum << endl;
////	vector<pii> v;
////	for (int i=0; i<n; i++) {
////		int prev = (i-1+n)%n;
////		ll dif = -1*min(b[i],a[(i+1)%n]) + a[i];
////		v.push_back(pii(dif, i));
////	}
////	sort(v.begin(), v.end());
////	ll sum = 0;
////	for (pii i : v) {
////		sum += a[i.second];
////		ll nxt = (i.second+1)%n;
////		ll diff = a[nxt]-b[i.second];
////		a[nxt] = diff;
////		if (a[nxt] < 0) a[nxt] = 0;
//////		cout << a[i.second] << endl;
////	}
////	cout << sum << endl;
//}
//int main() {
//	//local variables
//
//	//input
//	int t; cin >> t;
//	for (int i=1; i<=t; i++) solve();
//
//	//main
//
//	//output
//
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
    while(t--){
         int n;
         cin>>n;
         bool flag=true;
         int p1=0,c1=0,p,c;
         while(n--){
                  cin>>p>>c;
         if(p<p1||c<c1||c>p||(p==p1&&c>c1)||(p-p1<c-c1))
            flag=false;
            p1=p;
            c1=c;

         }
         if(flag)
            cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;
    }
}
