#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>
#include <string>
#include <ctype.h>

namespace IO {
    /* INPUT */
    char nc() { return getchar_unlocked(); }
    template<class T> void ri(T &x) {
        int sgn=1; char ch; x=0;
        while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
        x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
        x *= sgn; }
    template<class T, class... Ts> void ri(T& t, Ts&... ts) {
        ri(t); ri(ts...); }
    /* OUTPUT */
    void wc(char ch) { putchar_unlocked(ch); }
    void ws(std::string x) { for(char ch : x) wc(ch); }
    template<class T> inline void wi(T x) {
        if(x < 0) x*=-1, wc('-');
        if(0 <= x && x <= 9) wc('0'+x);
        else wi(x/10), wc('0'+x%10); }
};
using namespace IO;

int main() {

    int t; ri(t);
    while(t--) {
        int a,b; ri(a,b);
        if ((a+b)%3==0 && a*2>=b && b*2>=a) ws("YES\n");
        else ws("NO\n");
    }

}