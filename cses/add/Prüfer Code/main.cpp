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

priority_queue<int, vector<int>, greater<int> > pq;
int fro() {
    int top = pq.top(); pq.pop();
    return top;
}

int main() {

    int n, a[maxn], b[maxn], c[maxn];
    cin >> n;
    FOR(i,1,n) a[i] = b[i] = c[i] = -1;
    FOR(i,1,n-2) {
        cin >> a[i];
        b[a[i]] = i;
    }
    FOR(i,1,n+1) {
        if (b[i] == -1) pq.push(i);
        else c[b[i]] = i;
    }
    FOR(i,1,n-2) {
        cout << fro() << " " << a[i] << "\n";
        if (c[i] != -1) pq.push(c[i]);
    }
    cout << fro() << " " << fro();

}