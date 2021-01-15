#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}
void rs (string &x) {
    int c; x=""; c=getchar_unlocked();
    for(; c!=EOF && c!=' ' && c!='\n'; c=getchar_unlocked()) x+=c;
}
inline void wi(int x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n+1);
    int L = 1, R = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= R) z[i] = min(z[i - L + 1], R - i + 1);
        while (i + z[i] <= n && s[z[i]] == s[i + z[i] - 1]) z[i]++;
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

const int MOD = 1e9+7;

int main() {

    int n,m,r,C[105][26],dp[1005][105];
    string s,t,v,u;
    ri(n); rs(s);
    m = s.length();

    F0R(i,m) {
        F0R(c,26) {
            v = t + char(c+'A');
            u = s + "-" + v;
            r = 0;
            auto z = z_function(u);
            FOR(j,m+2,m+v.length()+1) {
                if (j+z[j] == m+v.length()+2) {
                    r = z[j];
                    break;
                }
            }
            C[i][c] = r;
        }
        t += s[i];
    }
    F0R(i,n+1) F0R(j,m+1) dp[i][j]=0;
    dp[0][0] = 1;
    F0R(i,n) {
        F0R(j,m) if (dp[i][j]) {
            F0R(c,26) {
                int nj = C[j][c];
                dp[i+1][nj] = (dp[i+1][nj] + dp[i][j]) % MOD;
            }
        }
        dp[i+1][m] = (dp[i+1][m] + (1LL * dp[i][m] * 26 % MOD)) % MOD;
    }
    wi(dp[n][m]);
}