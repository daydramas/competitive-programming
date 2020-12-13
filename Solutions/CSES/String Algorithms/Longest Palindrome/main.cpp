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

/* src: benq */
#define str string
#define bk back()
#define sz(x) (int) (x).size()

vi manacher(str s) {
	str s1 = "@"; trav(c,s) s1 += c, s1 += "#";
	s1.bk = '&';
	vi ans(sz(s1)-1); int lo = 0, hi = 0;
	FOR(i,1,sz(s1)-2) {
		if (i != 1) ans[i] = min(hi-i,ans[hi-i+lo]);
		while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i] ++;
		if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
	}
	ans.erase(begin(ans));
	F0R(i,sz(ans)) if ((i&1) == (ans[i]&1)) ans[i] ++;
	return ans;
}

int main() {
	// cerr <<"\n+------ Starting\n"; clock_t startT = clock();
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("input.in","r",stdin);
	// freopen("output.in","w",stdout);
    string s; cin >> s;
    auto x=manacher(s);
    // trav(a,x) cout << a <<"\n";
    pair<int,int> ans = {-1,-1};
    F0R(i,x.size()) ans = max(ans,{x[i],i});
    cout << s.substr((ans.s+1)/2-ans.f/2,ans.f);
	// cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds "<<endl<<endl;

}