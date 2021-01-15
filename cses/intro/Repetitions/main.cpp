#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int ans=1, cur=1;
    for (int i=1; i<s.length(); i++) {
        if(s[i]==s[i-1]) ans=max(ans, ++cur);
        else cur=1;
    }
    cout<<ans;
}