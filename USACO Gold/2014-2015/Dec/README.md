<div align="center"> [guard.cpp](#0) | [marathon.cpp](#1) </div>

# [guard.cpp](#0)
```cpp
/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

// declare any structures
#define ll long long

struct cow {
	ll height, weight, strength;
};
#define BIG 100000000000000
// declare any global variables
ll N, Mark, powerOfTwo[21];
ll dp[1<<21], W[1<<21], H[1<<21];
cow cows[21];
ll ans = -1;
// declare any functions
void solve(ll arr[], ll data[], ll start, ll end, ll index, ll r){
    if (index == r+1){

    	ll originalDecimal = 0;
    	for(ll j=1; j<=r; j++) originalDecimal += powerOfTwo[data[j]];
//    	cout<<":"<<originalDecimal<<endl;
    	ll preDecimal;
    	for(ll j=1; j<=r; j++) {
    		ll weight = cows[data[j]].weight;
    		ll strength = cows[data[j]].strength;
    		ll height = cows[data[j]].height;
    		preDecimal = originalDecimal-powerOfTwo[data[j]];
//    		if(W[originalDecimal] != W[preDecimal]+weight && W[originalDecimal]!=-BIG) cout << "weight pro"<<endl;
//    		if(H[originalDecimal] != H[preDecimal]+height && H[originalDecimal]!=-BIG) cout << "height pro"<<endl;
    		W[originalDecimal] = W[preDecimal]+weight;
			H[originalDecimal] = H[preDecimal]+height;

//			if(W[preDecimal]==-BIG) cout<<"Weight problem"<<endl;
//			if(H[preDecimal]==-BIG) cout<<"Height problem"<<endl;
//			if(H[originalDecimal] < Mark) continue;
//    		if(dp[originalDecimal]==1000000000) dp[originalDecimal] = -1000000000;

//    		ll temp_strength = strength - W[preDecimal];

    		if(strength >= W[preDecimal] && (dp[preDecimal]!=BIG||preDecimal==0)) { // if valid
    			ll safety_factor = min(strength - W[preDecimal], dp[preDecimal]);
//    			cout<<strength<<" "<<W[preDecimal]<<" "<<dp[preDecimal]<<endl;
    			if (dp[originalDecimal]==BIG || dp[originalDecimal]<safety_factor){
//    				if (safety_factor == 171913842) cout<<"find: "<<originalDecimal<<" "<<strength<<" "<<W[preDecimal]<<" "<<dp[preDecimal]<<" "<<preDecimal<<endl;
    				dp[originalDecimal]=safety_factor;
//    				W[originalDecimal] = W[preDecimal]+weight;
//    				H[originalDecimal] = H[preDecimal]+height;
//    				cout<<"dp["<<originalDecimal<<"] = "<<dp[originalDecimal]<<endl;
//    				cout<<"dp["<<originalDecimal<<"] = min("<<strength<<"-"<<W[preDecimal]<<", "<<dp[preDecimal]<<")"<<endl;
//    				cout<<"W["<<originalDecimal<<"] = "<<W[originalDecimal]<<endl;
//    				cout<<"H["<<originalDecimal<<"] = "<<H[originalDecimal]<<endl;
    			}

                if(H[originalDecimal]>=Mark && dp[originalDecimal]!=BIG) {
//        			cout<<strength<<" "<<W[preDecimal]<<" "<<dp[preDecimal]<<endl;

//                	cout << ans << " dpo: " << dp[originalDecimal]<< " dpp: "<<dp[preDecimal] << " odec:  " << originalDecimal << " pdec: " << preDecimal << " Hodec: "<<H[originalDecimal]<< " Wodec: "<<W[originalDecimal]<<" Hpdec: "<<H[preDecimal]<< " Wpdec: "<<W[preDecimal]<< " strength: "<<strength<<endl;
                	ans = max(ans, dp[originalDecimal]);
//                	cout <<ans<<" "<<originalDecimal<<endl;
                }
    		}
    	}
        return;
    }
    for (ll i=start; (i <= end) && (end-i+1>=r-index); i++) {
        data[index] = arr[i];
        solve(arr, data, i+1, end, index+1, r);
    }
}
int main() {

	// fstream
	ifstream fin ("guard.in");
	ofstream fout ("guard.out");

	// input
	fin >> N >> Mark;
	for(ll i=1; i<=N; i++) fin >> cows[i].height >> cows[i].weight >> cows[i].strength;
	for(ll i=0; i<(1<<N); i++){
		dp[i] = BIG;
		W[i] = -BIG;
		H[i] = -BIG;
	}
	powerOfTwo[1] = 1;
	for(ll i=2; i<=N; i++) {
		powerOfTwo[i] = powerOfTwo[i-1]*2;
	}
	// main
	W[0] = H[0] =0;
	for(ll i=1; i<=N; i++) { // size
		ll arr[21], data[21]; for(ll j=1; j<=N; j++) arr[j] = j;
		solve(arr, data, 1, N, 1, i);
	}
	// output
//	for(ll i=1; i<(1<<N); i++){
//		cout <<"W["<<i<<"] = " << W[i] << " H["<<i<<"] = "<<H[i]<<endl;
//	}
//	cout<<endl;
	if(ans!=-1) fout << ans << endl;
	else fout<<"Mark is too tall"<<endl;
	//close
	fout.close();
	return 0;
}

```

# [marathon.cpp](#1)
```cpp
/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int maxn = 1 << 17;
int n, q;
pii checkpoint[maxn];
int delta[2 * maxn];
int dist[2 * maxn];

int qa, qb;
int DistBetween(int a, int b) {
	return abs(checkpoint[a].first - checkpoint[b].first) + abs(checkpoint[a].second - checkpoint[b].second);
}

void build_ST(int rt, int a, int b) {
	if (a > b) return;
	if (a == b) {
		if (a < n - 1) delta[rt] = DistBetween(a, a + 1) + DistBetween(a + 1, a + 2) - DistBetween(a, a + 2);
		else delta[rt] = 0;
		if (a < n) dist[rt] = DistBetween(a, a + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	build_ST(rt * 2, a, mid);
	build_ST(rt * 2 + 1, mid + 1, b);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

int query_dist(int rt, int a, int b) {
	if (a > qb || b < qa) return 0;
	if (qa <= a && b <= qb) return dist[rt];
	int mid = (a + b) / 2;
	return query_dist(rt * 2, a, mid) + query_dist(rt * 2 + 1, mid + 1, b);
}

int query_delta(int rt, int a, int b) {
	if (a > qb || b < qa) return 0;
	if (qa <= a && b <= qb) return delta[rt];
	int mid = (a + b) / 2;
	return max(query_delta(rt * 2, a, mid), query_delta(rt * 2 + 1, mid + 1, b));
}

void update_dist(int rt, int a, int b) {
	if (a > qb || b < qa) return;
	if (qa <= a && b <= qb) {
		if (a >= 1 && a < n) dist[rt] = DistBetween(a, a + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	update_dist(rt * 2, a, mid);
	update_dist(rt * 2 + 1, mid + 1, b);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

void update_delta(int rt, int a, int b) {
	if (a > qb || b < qa) return;
	if (qa <= a && b <= qb) {
		if (a >= 1 && a < n - 1) delta[rt] = DistBetween(a, a + 1) + DistBetween(a + 1, a + 2) - DistBetween(a, a + 2);
		else delta[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	update_delta(rt * 2, a, mid);
	update_delta(rt * 2 + 1, mid + 1, b);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
}

int main() {
	// fstream
	ifstream fin ("marathon.in");
	ofstream fout ("marathon.out");

	fin >> n >> q;
	for (int i = 1; i <= n; i++) {
		fin >> checkpoint[i].first >> checkpoint[i].second;
	}
	build_ST(1, 1, n);
	for (int i = 0; i < q; i++) {
		char c[2];
		fin >> c;
		if (c[0] == 'Q') {
			fin >> qa >> qb;
			qb--;
			int tot = query_dist(1, 1, n);
			qb--;
			int del = query_delta(1, 1, n);
			fout << tot - del << endl;
		}
		else {
			int ix, pa, pb;
			fin >> ix >> pa >> pb;
			checkpoint[ix].first = pa;
			checkpoint[ix].second = pb;
			for (int j = ix - 1; j <= ix; j++) {
				qa = j; qb = j;
				update_dist(1, 1, n);
			}
			for (int j = ix - 2; j <= ix; j++) {
				qa = j; qb = j;
				update_delta(1, 1, n);
			}
		}
	}
}

```

