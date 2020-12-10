#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>
using namespace std;

using ll = long long;
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
inline void wi(int x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

const int maxn = 1e5+5;

int n, A[maxn], B[maxn], L[maxn], R[maxn];

void dfs(int a, int b, int sz) {
    int root = A[a];
    if (root == 0) return;
    if (sz <= 0) return;
    int leftS = B[root]-b;
    int rightS = sz+b-B[root]-1;
    dfs(a+1, b, leftS);
    dfs(a+leftS+1, b+leftS+1, rightS);
    wi(root); putchar_unlocked(' ');
}
int main() {

    ri(n);
    FOR(i,1,n) A[i]=B[i]=0;
    FOR(i,1,n) ri(A[i]);
    FOR(i,1,n) { int x; ri(x); B[x]=i; }
    dfs(1,1,n);
}