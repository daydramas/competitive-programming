template<int SZ> struct BinCoef {
    ll fact[SZ+5];
    ll MOD = 1e9+7;

    ll pw(ll a, ll b) {
        if (b == 0) return 1LL;
        return pw((a*a)%MOD, b/2) * (b&1?a:1LL) % MOD;
    }

    ll ifact(int i) { return pw(fact[i], MOD-2); }

    BinCoef(ll _MOD = 1e9+7) {
        MOD = _MOD;
        fact[0]=1;
        FOR(i,1,SZ) fact[i] = (fact[i-1]*i) % MOD;
    }

    ll get(int a, int b) {
        if (a < b) return 0;
        return (fact[a]*ifact(a-b) % MOD * ifact(b) % MOD);
    }

};