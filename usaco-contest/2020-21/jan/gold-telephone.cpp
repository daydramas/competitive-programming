#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include "bits/stdc++.h"
using namespace std;

const int N = 5e4+5;
const int K = 55;

int n, k, t[N];
vector<int> tg[K], g[K];

int d[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> t[i];
		tg[t[i]].push_back(i);
	}
	for(int i=1; i<=k; i++) {
		string s; cin >> s;
		for(int j=1; j<=k; j++) {
			if(s[j-1] == '1') {
				g[i].push_back(j);
			}
		}
	}
	using T = pair<int,int>;
	priority_queue<T, vector<T>, greater<T>> Q;
	for(int i=1; i<=n; i++) d[i] = 1e9;
	d[1] = 0;
	Q.push({0,1});
	while(Q.size()) {
		T f = Q.top(); Q.pop();
		if(d[f.second] < f.first) continue;
		for(int i : g[t[f.second]]) {
			for(int s : tg[i]) {
				int nd = d[f.second] + abs(f.second-s);
				if(nd < d[s]) {
					d[s] = nd;
					Q.push({nd, s});
				}
			}
		}
	}
	if(d[n] == 1e9) cout << "-1\n";
	else cout << d[n];
}