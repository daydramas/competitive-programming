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
	vector<pll> H[5005];
	vector<pair<int,pll>> S;
	vector<string> T;
	cerr <<"\n+------ Starting\n"; clock_t startT = clock();
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
    string s;
    cin >> s; hsh n; n.init(s);
	int m; cin >> m; int mss=0;
    F0R(i,m) {
        string t; cin >> t; T.pb(t);
		if (mss<t.size()) mss=t.size();//mss = max(mss, t.size());
    }
	F0R(i,n.N) {
		pll h={0, 0};
		FOR(j,i,n.N-1) {
			if (j-i+1 > mss) break;
			h=BASE*h+s[j], H[j-i+1].pb(h);
		}
	} FOR(i,1,n.N) sort(all(H[i]));
	trav(t, T) {
		if (t.length()>n.N) continue;
		pll h=get_hash(t);
		// cout << i <<" "<<h.f<<"-"<<h.s<<"\n";
		auto it=lower_bound(all(H[t.length()]), h);
		if (it == H[t.length()].end() || *it!=h) continue;
        S.push_back({t.length(),h});
	} sort(all(S));
	cerr <<"+------ Ck 0 | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    int dp[5005]; memset(dp, 0, sizeof(dp)); dp[0]=1;
	cerr <<"+------ Ck 1 | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
	int cnt=0, x;
    F0R(i,n.N) {
		x = dp[i];
		if(!x) continue;
		trav(t, S) { cnt++;
			if ((t.f+i)>n.N) break;
			if (n.get(i, i+t.f) != t.s) continue;
			dp[t.f+i] = (dp[t.f+i]+x) % MOD;
		}
    }
    cout << dp[n.N];
	cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds "<<cnt<<" iterations\n\n";
}