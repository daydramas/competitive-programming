/**
 * Description: String Hashing
 * Time: O(N) initialization, O(1) calculation
 * Source: USACO Guide
*/

const ll MOD = 1e9 + 9;
const ll BASE = 9973;

void calc_pw(int &n, vector<ll> &pw) {
    pw[0] = 1;
    for (int i=0; i<n; i++) pw[i+1] = (pw[i] * BASE) % MOD;
}

void calc_hashes(int &n, vector<ll> &hsh, string &s) {
    hsh[0] = 1;
    for (int i=0; i<n; i++)
        hsh[i + 1] = ((hsh[i] * BASE) % MOD + s[i]) % MOD;
}

ll get_hash(vector<ll> &hsh, vector<ll> &pw, int &a, int &b) {
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % MOD + MOD) % MOD;
}