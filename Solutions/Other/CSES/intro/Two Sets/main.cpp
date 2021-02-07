#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    ll n; cin >> n;
    ll t = n*(n+1)/2;
    if (t%2) { cout <<"NO"; return 0; }
    t /= 2;
    vector<int> a, b;
    do {
        if (t-n >= 0) {
            t -= n;
            a.push_back(n);
        } else b.push_back(n);
    } while(--n);
    cout <<"YES\n";
    cout << a.size()<<"\n";
    for (int i=0; i<a.size(); i++) cout <<a[i]<<" ";
    cout << "\n"<< b.size()<<"\n";
    for (int i=0; i<b.size(); i++) cout <<b[i]<<" ";
    cout <<"\n";
}