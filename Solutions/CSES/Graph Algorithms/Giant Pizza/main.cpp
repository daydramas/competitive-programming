/* LOL I didn't use SCC */

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
const int MX=1e5+5;
int w1[MX], w2[MX], d[MX], r[MX];

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
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
        int v1=abs(w1[i]), v2=abs(w2[i]);
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
        cout <<"IMPOSSIBLE"; return 0;
    }
    for(int i=1; i<=m; i++) {
        if (r[i]==-1) putchar_unlocked('-');
        else putchar_unlocked('+');
        putchar_unlocked(' ');
    }
    return 0;
}