#include <stdio.h>
#include <unordered_set>

inline int read(){
	int t = 0;
	char c;
	while((c=getchar_unlocked())!='\n'&&c!=' '&&c!=EOF) t=t*10+c-48;
	return t;
}
int main() {

    int n, k[200000];
    std::unordered_set<int> t;

    int aa=0, i, b=0;

    n = read();
    for(i=0; i<n; i++) k[i] = read();
    t.reserve(n);
    for(i=0; i<n; i++){
        while(t.find(k[i]) != t.end()) t.erase(k[i-(b--)]);
		if(k[i] != 0) t.insert(k[i]), b++;
		if(b>aa) aa=b;
    }
    printf("%d\n", aa);
}