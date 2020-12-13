#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

const int maxn = 2e5+5;
int n, a[maxn], cnt=0;
vector<vi> ans; vi tmp;
vector<pair<int,int>> ta;

void calc() {
    bool c[maxn];
    FOR(i,1,n) c[i]=false;
    FOR(i,1,n) if(!c[i]) {
        tmp.clear();
        int d=a[i];
        tmp.pb(d);
        while(d!=i) c[d]=1, d=a[d], tmp.pb(d);
        ans.pb(tmp);
        cnt=max(cnt, (int)tmp.size());
        c[d]=true;
    }
}
void print() {
    cout << ta.size() <<"\n";
    trav(x,ta) cout << x.f <<" "<<x.s<<"\n";
    ta.clear();
}
int main() {

    cin >> n;
    FOR(i,1,n) cin >> a[i];
    calc();
    if (cnt==1) {
        cout <<"0";
    } else if (cnt==2) {
        cout <<"1\n";
        trav(x, ans) if(x.size()==2)
            ta.pb({x[0], x[1]});
        print();
    } else {
        cout <<"2\n";
        trav(x, ans) {
            int s=x.size();
            if(s==2) ta.pb({x[0], x[1]});
            else if(s>2) F0R(i,s)
                if(i<(s-i)%s) ta.pb({x[i],x[(s-i)%s]});
        }
        print();
        trav(x, ans) {
            int s=x.size();
            // if(s==2) ta.pb({x[0], x[1]});
            /*else */if(s>2) F0R(i,s)
                if(i<(s+1-i)%s) ta.pb({x[i],x[(s+1-i)%s]});
        }
        print();
    }
}