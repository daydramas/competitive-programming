#include <bits/stdc++.h>
using namespace std;

int hash(string a) {
    int result = 1;
    for(char ch: a) {
        result = (result * (ch-'A'+1)) % 47;
    }
    return result;
}

int main() {
    ifstream cin("ride.in");
    ofstream cout("ride.out");

    string a, b; cin >> a >> b;
    int hash1, hash2;
    hash1 = hash(a);
    hash2 = hash(b);
    if(hash1 == hash2) {
        cout << "GO\n";
    } else {
        cout <<"STAY\n";
    }
}