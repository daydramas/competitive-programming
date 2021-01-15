#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>
#include <algorithm>
#include <vector>
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

struct BIT {

	int n; vi t;

	BIT(int n_) { n = n_; t.assign(n+1, 0); }

	void upd(int i, int value) {
		for (; i<=n; i+=i&(-i)) t[i] += value;
	}

	int qry(int i) {
		int sum = 0;
		for(; i>0; i-=i&(-i)) sum += t[i];
		return sum;
	}

};

void ri (int &x) {
    int c,s=1; x = 0;
    c=getchar_unlocked();
    if (c == '-') s*=-1, c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
    x = x*s;
}
inline void wi(int x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

int n; vector<vi> v;
BIT bit(2000005);

int main() {

    ri(n);
    F0R(i,n) {
        int x1,y1,x2,y2; ri(x1);ri(y1);ri(x2);ri(y2);
        if (y1 == y2) v.pb({y1,2,x1,x2});
        else v.pb({y1,1,x1,1}), v.pb({y2,3,x1,1});
    }
    sort(all(v)); ll ans=0; trav(x, v) {
        x[2] += 1000001, x[3] += 1000001;
        if (x[1] == 1) bit.upd(x[2],1);
        else if (x[1] == 2) ans += bit.qry(x[3])-bit.qry(x[2]-1);
        else bit.upd(x[2],-1);
    }
    wi(ans);
}