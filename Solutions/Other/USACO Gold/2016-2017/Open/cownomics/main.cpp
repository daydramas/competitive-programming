#include <bits/stdc++.h>
using namespace std;

// structures/defines

#define ll long long

    const ll MOD = 1e9 + 9;
    const ll BASE = 9973;

    void calc_pw(int &n, vector<ll> &pw) {
        pw[0] = 1;
        for (int i=0; i<n; i++) pw[i+1] = (pw[i] * BASE) % MOD;
    }

    void calc_hashes(int &n, vector<ll> &hsh, string &s) {
        hsh[0] = 1;
        for (int i=0; i<n; i++)
            hsh[i + 1] = ((hsh[i] * BASE) % MOD + s[i]) % MOD;
    }

    ll get_hash(vector<ll> &hsh, vector<ll> &pw, int &a, int &b) {
        return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % MOD + MOD) % MOD;
    }

// global variables
int N, M;
string spotty[501], plain[501];

vector<ll> spottyH[501], plainH[501];
vector<ll> pw;

//functions
bool possible(int sz) {
	int combo = M-sz+1;
//	cout << sz << " " << combo << endl;
	bool ans = false;
	for(int s=0; s<combo; s++) {
		set<ll> S; int tans = 0;
		for(int i=1; i<=N; i++) {
			int e = s+sz-1;
			S.insert(get_hash(spottyH[i], pw, s, e));
		}
		bool flag = true;
		for(int i=1; i<=N; i++) {
			int e = s+sz-1;
			if(S.count(get_hash(plainH[i], pw, s, e))>0) {
				flag = false;
				break;
			}
		}
		if(flag) return true;
	}
	return false;
}
int main() {
	// local variables

	// fstream
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");

	// input
	fin >> N >> M;
	for(int i=1; i<=N; i++) {
		fin >> spotty[i];
		spotty[i] = spotty[i];
	}
	for(int i=1; i<=N; i++) {
		fin >> plain[i];
		plain[i] = plain[i];
	}

	// main
	pw.resize(M+1);
	calc_pw(M, pw);
	for (int i=1; i<=N; i++) {
		spottyH[i].resize(M+1), plainH[i].resize(M+1);
		calc_hashes(M, spottyH[i], spotty[i]);
		calc_hashes(M, plainH[i], plain[i]);
	}
	int s=1, b=M;
	while(s<b) {
		int m=(s+b)/2;
		if(possible(m)) {
			b = m;
		} else {
			s = m+1;
		}
	}
	// output
	fout << s << endl;
	return 0;
}

  