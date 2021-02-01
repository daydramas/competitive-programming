/**
 * Q - Longest Match
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define N	(1<<18) // 2e5

typedef long long LL;

const LL MOD = 1e9 + 7;
const LL BASE = 9973;



bool letter(char ch) {
	if(ch >= 'a' && ch <= 'z') return 1;
	if(ch >= 'A' && ch <= 'Z') return 1;
	return 0;
}
char tolow(char ch) {
	if(ch >= 'a' && ch <= 'z') return ch;
	return ('a' + ch - 'A');
} 
void append(LL &hsh, char c) {
	hsh = ( (BASE * hsh) % MOD + tolow(c) ) % MOD;
}
void ins(vector<LL> &x, LL &y) {
	if(y) x.push_back(y);
	y = 0;
}
int solve(string &a, string &b) {
	LL ha = 0, hb = 0;
	vector<LL> A, B;
	for(char c : a) {
		if(!letter(c)) ins(A, ha);
		else append(ha, c);
	} ins(A, ha);
	for(char c : b) {
		if(!letter(c)) ins(B, hb);
		else append(hb, c);
	} ins(B, hb);
	vector<vector<int> > dp(A.size()+1, 
			vector<int>(B.size()+1));
	dp[0][0] = 0;
	for(int i=1; i<=A.size(); i++)
	for(int j=1; j<=B.size(); j++) {
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
	}
	return dp[A.size()][B.size()];

}

int main() {

	int test_case = 1;
	static string a, b;
	while(getline(cin, a)) {
		getline(cin, b);
		cout << test_case++ << ". ";
		if(a.length() == 0 || b.length() == 0) {
			cout << "Blank!";
		} else {
			cout << "Length of longest match: " << solve(a, b);
		}
		cout << '\n';
	}
}