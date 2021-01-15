#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

/* LOL I didn't use SCC */
#include <stdio.h>
#include <stdlib.h>

#define pc putchar_unlocked

inline void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

int n, m;
const int MX=1e5+5;
int w1[MX], w2[MX], d[MX], r[MX];


int main() {

    ri(n); ri(m);
    for(int i=1; i<=n; i++) {
        char s1, s2;
        s1=getchar_unlocked(); getchar_unlocked(); ri(w1[i]);
        s2=getchar_unlocked(); getchar_unlocked(); ri(w2[i]);
        if (s1=='-') d[w1[i]]--, w1[i] *= -1;
        else d[w1[i]]++;

        if (s2=='-') d[w2[i]]--, w2[i] *= -1;
        else d[w2[i]]++;
    }
    for(int i=1; i<=n; i++) {
        int v1=abs(w1[i]);
        int v2=abs(w2[i]);
        if (r[v1]!=0 && r[v1]==(w1[i]/v1)) { continue; }
        if (r[v2]!=0 && r[v2]==(w2[i]/v2)) { continue; }
        if (r[v1]!=0 && r[v2]==0) { r[v2]=(w2[i]/v2); continue; }
        if (r[v1]==0 && r[v2]!=0) { r[v1]=(w1[i]/v1); continue; }
        if (r[v1]==0 && r[v2]==0) {
            int m1=d[v1]/(w1[i]/v1);
            int m2=d[v2]/(w2[i]/v2);
            if (m1>m2) { r[v1]=(w1[i]/v1); }
            else { r[v2]=(w2[i]/v2); }
            continue;
        }
        pc('I'),pc('M'),pc('P'),pc('O'),pc('S'),pc('S'),pc('I'),pc('B'),pc('L'),pc('E');
        return 0;
    }
    for(int i=1; i<=m; i++) {
        if (r[i]==-1) pc('-');
        else pc('+');
        pc(' ');
    }
    return 0;
}