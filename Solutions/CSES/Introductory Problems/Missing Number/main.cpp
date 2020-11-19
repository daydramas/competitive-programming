#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n, 1);
    while(--n) {
        int b; cin >> b;
        a[--b]=0;
    }
    int idx=0;
    while(!a[idx++]);
    cout << idx;
}