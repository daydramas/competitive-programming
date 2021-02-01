/**
 * CSES Money Sums
 * https://cses.fi/problemset/task/1745/
*/

#include <bitset>
using namespace std;

const int N = 100001;


int main() {

	int n, x;
	bitset<N> ans(1);

	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		ans |= ans << x;
	}
	printf("%d\n", ans.count()-1);
	for(int i=1; i<N; i++) if(ans[i])
		printf("%d ", i);
	printf("\n");
}