/*
    ID: dongliu3
    PROG: crypt1
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, *l;

bool F(int x) {
    while(x) {
        int d=x%10;
        bool flag=false;
        for(int i=0; i<n; i++) if(d==l[i]) flag=true;
        if(!flag) return false;
        x/=10;
    }
    return true;
}

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    fin >> n;
    l = new int[n];
    for(int i=0; i<n; i++) fin >> l[i];

    int ans = 0;
    for(int ai=0; ai<n; ai++)
    for(int bi=0; bi<n; bi++)
    for(int ci=0; ci<n; ci++)
    for(int di=0; di<n; di++)
    for(int ei=0; ei<n; ei++) {
        int a=l[ai], b=l[bi], c=l[ci], d=l[di], e=l[ei];
        int f = (100*a+10*b+c)*e;
        if(F(f) && f<1000 && f>=100) {
            int g = (100*a+10*b+c)*d;
            if(F(g) && g<1000 && g>=100) {
                int h = f+10*g;
                if(F(h) && h<10000 && h>=1000) {
                    // cout << a << b << c <<" * "<< d << e << " = "<<f <<" + "<<10*g <<" = "<<h<<"\n";
                    ans++;
                }
            }
        }
    }
    fout << ans << '\n';
}