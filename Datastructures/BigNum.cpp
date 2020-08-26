struct bignum {
    vi v;
    bignum(vector<int> v) : v(v) {}
    bignum(int x) {
        v.resize(MX, 0);
        for (int i=0; i<MX && x!=0; i++) {
            v[i] = x % 10;
            x /= 10;
        }
    }
    bignum operator+(const bignum &x) {
        vi out(MX, 0);
        int carry = 0;
        for0(i, MX) {
            out[i] = v[i] + x.v[i] + carry;
            carry = out[i] / 10;
            out[i] %= 10;
        }
        return bignum(out);
    }
    bignum operator-(const bignum &x) {
        vi out = v;
        for0(i, MX) {
            if (out[i] < x.v[i]) {
                out[i + 1]--;
                out[i] += 10;
            }
            out[i] -= x.v[i];
        }
        return bignum(out);
    }
    bignum operator*(const int x) {
        vi out = v;
        int carry = 0;
        for0(i, MX) {
            out[i] = out[i]*x + carry;
            carry = out[i]/10;
            out[i] %= 10;
        }
        return bignum(out);
    }
    void print() {
        int in = MX-1;
        while (in > 0 && v[in] == 0) in--;
        while (in >= 0) cout << v[in--];
        cout <<"\n";
    }
};