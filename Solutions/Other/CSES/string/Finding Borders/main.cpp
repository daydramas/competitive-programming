#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

/* source: ekzlib */
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const pll BASE = {9973, 7817};

pll operator+(const pll& a, const pll& b) {
	return { (a.first + b.first) % MOD, (a.second + b.second) % MOD };
}
pll operator+(const pll& a, const ll& b) {
	return { (a.first + b) % MOD, (a.second + b) % MOD };
}
pll operator-(const pll& a, const pll& b) {
	return { (MOD + a.first - b.first) % MOD, (MOD + a.second - b.second) % MOD };
}
pll operator*(const pll& a, const pll& b) {
	return { (a.first * b.first) % MOD, (a.second * b.second) % MOD };
}
pll operator*(const pll& a, const ll& b) {
	return { (a.first * b) % MOD, (a.second * b) % MOD };
}

pll get_hash(string s) {
	pll h = {0, 0};
	for (int i = 0; i < s.size(); i++) {
		h = BASE * h + s[i];
	}
	return h;
}

struct hsh {
	int N;
	string S;
	vector<pll> pre, pp;

	void init(string S_) {
		S = S_;
		N = S.size();
		pp.resize(N);
		pre.resize(N + 1);
		pp[0] = {1, 1};
		for (int i = 0; i < N; i++) {
			pre[i + 1] = pre[i] * BASE + S[i];
			if (i) { pp[i] = pp[i - 1] * BASE; }
		}
	}

	pll get(int s, int e) {
		return pre[e] - pre[s] * pp[e - s];
	}
};

int main() {

    string s; cin >> s;
    hsh n; n.init(s);
    FOR(i,1,n.N-1) {
        if(n.get(0,i) == n.get(n.N-i, n.N)) cout << i <<" ";
    }

}