#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>
#include <string>
#include <algorithm>
#include <ctype.h>

namespace IO {
    /* INPUT */
    char nc() { return getchar_unlocked(); }
    void rs(std::string& x) {
        char ch; x=""; while (isspace(ch = nc()));
        do { x += ch; } while (!isspace(ch = nc()) && ch != EOF); }
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

    std::string s, a="\n"; rs(s);
    int c=0; sort(s.begin(), s.end());
    do { a += s + "\n", c++; }
    while (std::next_permutation(s.begin(),s.end()));
    wi(c); ws(a);
}