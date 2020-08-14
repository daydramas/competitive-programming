/*
 _____     ______              ______                _______
 |     \   |      |  |\     |  |             |           |     |      |
 |	    \  |      |  | \    |  |             |           |     |      |
 |      |  |      |  |  \   |  |   ___       |           |     |      |
 |      |  |      |  |   \  |  |      |      |           |     |      |
 |      /  |      |  |    \ |  |      |      |           |     |      |
 |_____/   |______|  |     \|  |______|      |______  ___|___  |______|

 ___   ___        ___             ___   ___   ___  ___
 __ | __  |   | |    |   \   / |   | |___  |___| |    |   | \
     |___| |___| |___ |___/   \ |___|  ___| |   | |___ |___| /

 */

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <stack>
#include <utility>
using namespace std;

// structures/defines

// global variables
string S;
vector<string> T;
int N;
int g[100001][30];
int out[100001], f[100001];
//functions
void build() {
	memset(out, 0, sizeof out);
	memset(g, -1, sizeof g);
	int states = 1;
	for (int i = 0; i < N; ++i) {
		const string &word = T[i];
//		string word = T[i];
		int currentState = 0;
		for (int j = 0; j < word.size(); ++j) {
			int ch = word[j] - 'a';
			if (g[currentState][ch] == -1)
				g[currentState][ch] = states++;

			currentState = g[currentState][ch];
		}

		//		out[currentState] |= (1 << i);
		out[currentState] = i + 1;
	}

	for (int ch = 0; ch < 26; ++ch)
		if (g[0][ch] == -1)
			g[0][ch] = 0;
	memset(f, -1, sizeof f);

	queue<int> q;

	for (int ch = 0; ch < 26; ++ch) {
		if (g[0][ch] != 0) {
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}

	while (q.size()) {
		int state = q.front();
		q.pop();
		for (int ch = 0; ch <= 26; ++ch) {
			if (g[state][ch] != -1) {
				int failure = f[state];
				while (g[failure][ch] == -1)
					failure = f[failure];

				failure = g[failure][ch];
				f[g[state][ch]] = failure;
//				out[g[state][ch]] |= out[failure];
				q.push(g[state][ch]);
			}
		}
	}

}
int findNextState(int currentState, char nextInput) {
	int answer = currentState;
	int ch = nextInput - 'a';

	while (g[answer][ch] == -1)
		answer = f[answer];

	g[currentState][ch] = g[answer][ch];

	return g[answer][ch];
}

int main() {
	// local variables

	// fstream
	ifstream fin("censor.in");
	ofstream fout("censor.out");

	// input
	fin >> S >> N;
	for (int i = 0; i < N; i++) {
//		fin >> T[i];
		string tt;
		fin >> tt;
		T.push_back(tt);
//		out[i] = 0;
//		for(int j=0; j<=26; j++) {
//			g[i][j] = -1;
//		}
	}
//	for(int i=0; i<5; i++) {
//		cout << i << " "  << T[i]<<endl;
//	}
	/* Sort the search strings by length using a C++11 lambda expression. */
//	  sort(T.begin(), T.end(), [](const string& x, const string& y) -> bool {
//	                             return x.size() < y.size();
//	                           });
//	  cout <<endl;
	/*
	 *
	 *
	 */
//	for(int i=0; i<5; i++) {
//		cout << i << " "  << T[i]<<endl;
//	}
	build();
	// main
	string R = "";
	int R_i = 0;
	int bigJ[100001];
	bigJ[0] = 0;
	int currentState = 0;
	for (int i = 0; i < S.size(); ++i, R_i++) {
		R += S[i];
//		R[R_i+1] = S[i];
		currentState = findNextState(currentState, S[i]);
//		cout<<"R_i: "<<R_i<<" "<<currentState<<" " << R<<endl;
		bigJ[R_i] = currentState;

		// If match not found, move to next state
		if (out[currentState] == 0)
			continue;

		// Match found, print all matching words of arr[]
		// using output function.
		for (int j = 0; j < N; ++j) {
			if (out[currentState] == j + 1) {
//				if (out[currentState] & (1 << j)) {
				R_i = R_i - T[j].size();

				R.resize(R_i + 1);
//				R_i = R.size() - 1;
				currentState = bigJ[R_i];
//				cout<<i<<" "<<j<<" "<<bigJ[R_i]<<endl;
				break;
			}
		}
//		currentState = bigJ[R_i];

	}

	// output
	fout << R << endl;
	return 0;
}
