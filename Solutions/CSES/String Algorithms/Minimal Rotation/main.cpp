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

int get(string s) {
    int x=0, n=s.length(); s += s;
    F0R(i,n) F0R(j,n) {
        if (x+j == i || s[x+j] < s[i+j]) {i += max(0, j-1); break;}
        if (s[x+j] > s[i+j]) { x = i; break; }
    }
    return x;
}

int main() {

    string s; cin >> s;
    auto x = get(s);
    cout << s.substr(x,s.length()-x)+s.substr(0,x);
}