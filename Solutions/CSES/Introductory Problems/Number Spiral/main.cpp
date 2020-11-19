#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ll n,x,y; cin >> n;
    while(n--) {
        cin >> x >> y;
        cout << ( (x<y)?(y%2?(y*y-x+1):((y-1)*(y-1)+x)):(x%2?((x-1)*(x-1)+y):(x*x-y+1)) ); cout <<"\n";
    }
}