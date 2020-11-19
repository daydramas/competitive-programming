#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int a,b; cin>>a>>b;
        if((a+b)%3) cout <<"NO\n";
        else {
            if (min(a,b)*2 < max(a,b)) cout <<"NO\n";
            else cout <<"YES\n";
        }
    }
}