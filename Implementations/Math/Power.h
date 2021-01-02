ll pw(ll a, ll b, ll m=1e9+7) { // calculating a^b (mod m)
    if (b == 0) return 1LL;
    return pw((a*a)%m, b/2, m) * (b&1?a:1LL) % m;
}