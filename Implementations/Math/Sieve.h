#include <vector>
using namespace std;

vector<int> Sieve(int N) {
	vector<int> primes, composite(N+1);
	for(int i=2; i<=N; i++) {
		if(composite[i]) continue;
		primes.push_back(i);
		for(int j=i; j<=N; j+=i) composite[j] = true;
	}
	return primes;
}