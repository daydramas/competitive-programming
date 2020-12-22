#include "bits/stdc++.h"
using namespace std;

string N, M;

int main() {

	ifstream fin("ride.in");
	ofstream fout("ride.out");

	fin >> N >> M;

	auto code = [](string &S) {
		int ans = 1;
		for (char ch : S) ans = (ans * (ch-'A'+1)) % 47;
		return ans;
	};
	if(code(N) == code(M))
		fout << "GO\n";
	else
		fout << "STAY\n";

	return 0;
}