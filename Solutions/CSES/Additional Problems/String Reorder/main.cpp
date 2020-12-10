#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>
#include <string.h>
using namespace std;

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 1e6;

int main() {

    int n; char s[maxn]; int c[26];
    scanf("%s", s); n = strlen(s);
    F0R(i,n) c[s[i]-'A']++;
    F0R(i,26) if(n<(c[i]*2-1)) { puts("-1"); return 0; }
    int pre=-1;
    F0R(i,n) {
        int cur=0, cur2=0;
        while(cur<26 && (cur==pre || !c[cur])) cur++;
        FOR(j,1,25) cur2 = (c[cur2]<c[j] ? j : cur2);
        cur = (cur!=cur2 && n-i<2*c[cur2] ? cur2 : cur);
        c[cur]--; pre=cur; putchar('A'+cur);
    }
}