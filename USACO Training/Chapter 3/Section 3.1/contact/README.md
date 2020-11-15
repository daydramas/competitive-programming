```cpp
/*
 ID: dongliu3
 TASK: contact
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define l long long
#define ll long long
#define vl vector<ll>
// global variables
int A, B, N;
string sight;
map<ll, l> C;
map<l, vl> C2;

// functions
string ts(ll i) { return to_string(i); }
l c1(string str) { return stoll("1"+str); }
string c2(ll i) { return ts(i).substr(1, ts(i).size()-1); }

int main() {
	// local variables

	// fstream
	ifstream fin("contact.in");
	ofstream fout("contact.out");

	// input
	fin >> A >> B >> N;
	string temp; sight = ""; getline(fin, temp);
	while(fin.good()) {
		getline(fin, temp);
		sight += temp;
	}
	// main
	for (int i=A; i<=B; i++) if (i <= sight.length()) {
		string curr = sight.substr(0, i);
		C[c1(curr)] ++;
		for (int j=i; j<sight.length(); j++) {
			curr.erase(curr.begin());
			curr += sight[j];
			C[c1(curr)] ++;
		}
	}
	for (auto a : C) C2[a.second].push_back(a.first);
	for (auto a : C2) sort(a.second.begin(), a.second.end());
	for (auto a = C2.rbegin(); a!=C2.rend(); a++) {
		if (N == 0) break;
		int done = 0;
		fout << a->first << endl;
		for (auto i : a->second) {
			fout << c2(i);
			done++;
			if (!(done % 6) || i == a->second.back()) fout << endl;
			else fout << " ";
		}
		N--;
	}
	// output
	return 0;
}

```