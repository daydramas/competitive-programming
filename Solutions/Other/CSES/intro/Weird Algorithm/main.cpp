#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>

inline void ri (long long &x) {
    long long c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

inline void wi(long long x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

int main() {
    long long n; ri(n);
    while(n-1) {
        wi(n); putchar_unlocked(' ');
        n = n%2 ? n*3+1 : n>>1;
    }
    wi(n);
}