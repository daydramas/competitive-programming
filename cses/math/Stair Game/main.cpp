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

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

int main() {

    int t; cin>>t;//ri(t);
    while(t--) {
        int n,r=0; cin>>n;//ri(n);
        for(int i=0;i<n;i++) { int a; cin>>a;/*ri(a);*/ if(i&1){r^=a;} }
        cout << (r?"first":"second")<<"\n";
    }

}