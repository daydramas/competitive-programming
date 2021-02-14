#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int in;
//vector<string>ans;
//string ans;
int ans1, ans2;
int prime[2000], pin = 0;
//functions
bool comp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}
bool isPrime(int n) {
    if (n <= 1)return false;
    if (n <= 3)return true;

    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void getPrime(int n)
{
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
        	prime[pin++] = i;
    }
}
int main() {
	//local variables

	//input
	cin >> in;

	if (isPrime(in)) {
		cout << "1"<<to_string(in)<<endl;
		return 0;
	}
	cout <<"g-1: "<<'g'-'a'+1<<endl;

	//main
	getPrime(in);
	for (int i=0; i<pin; i++) {
		if (prime[i] > in/2) break;
		if (in%prime[i]) continue;
		for (int j=i; j<pin; j++)
			if (prime[i]*prime[j] == in) {
	//			ans = to_string(i)+to_string(j);
				ans1 = prime[i], ans2 = prime[j];
				break;
	//			ans.push_back(to_string(prime[i])+to_string(prime[j]));
	//			cout << to_string(prime[i])+to_string(prime[j]) << endl;
			}
	}
	//output
//	sort(ans.begin(), ans.end(), comp);
//	cout << ans[0] << endl;
//	cout << ans << endl;
	cout<<ans1<<ans2<<endl;
	return 0;
}
