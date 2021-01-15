#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int a, b; long long ans=0;
    for(int i=0; i<n; i++) {
        cin >> b;
        if(i) ans+=max(a-b, 0), b=max(b, a);
        a=b;
    }
    cout<<ans;
}