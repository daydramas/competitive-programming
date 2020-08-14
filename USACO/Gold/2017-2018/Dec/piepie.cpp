/*
 ID: dongliu3
 TASK: piepie
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
int N, D;
int B[200000], E[200000];
struct compA {
	bool operator()(int i, int j) const {
		return E[i] > E[j];
	}
};
struct compB {
	bool operator()(int i, int j) const {
		return B[i] > B[j];
	}
};
// global variables
multiset<int, compA> sA;
multiset<int, compB> sB;
int ans[200000];
//functions

int main() {
//  local variables

//  fstream
	ifstream fin("piepie.in");
	ofstream fout("piepie.out");

//  input
	fin >> N >> D;
	for (int i = 0; i < (2 * N); i++) {
		fin >> B[i] >> E[i];
	}
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (E[i] == 0) {
			Q.push(i);
//			cout <<"pushing "<< i << endl;
			ans[i] = 1;
		} else {
			sA.insert(i);
			ans[i] = -1;
		}
		if (B[i + N] == 0) {
			Q.push(i + N);
//			cout <<"pushing "<< i+N << endl;
			ans[i + N] = 1;
		} else {
			sB.insert(i + N);
			ans[i + N] = -1;
		}
	}

//	main
//	for (multiset<int, compB>::iterator it = sB.begin(); it != sB.end(); it++) {
//		cout << *it << " b: " << B[*it] << endl;
//	}
	while (!Q.empty()) {
		int f = Q.front();
//		cout << f << " ans: " << ans[f] << endl;
		Q.pop();
		if (f < N) {
			while (true) {
				multiset<int, compB>::iterator it = sB.lower_bound(f);
//				cout << *it << " : " << B[*it] << " versus " << B[f] << endl;
				if (it == sB.end() || B[*it] + D < B[f]) {
//					cout <<"break;"<<endl;
					break;
				}
//				cout << *it << " : " << B[*it] << " versus " << B[f] << endl;
				Q.push(*it);
				ans[*it] = ans[f] + 1;
				sB.erase(it);
			}
		} else if (f < 2 * N) {
			while (true) {
				multiset<int, compA>::iterator it = sA.lower_bound(f);
//				cout << *it << " : " << E[*it] << " versus " << E[f] << endl;
				if (it == sA.end() || E[*it] + D < E[f]) {
//					cout <<"break;"<<endl;
					break;
				}
//				cout << *it << " : " << E[*it] << " versus " << E[f] << endl;
				Q.push(*it);
				ans[*it] = ans[f] + 1;
				sA.erase(it);
			}
		}
	}
//	output
	for (int i = 0; i < N; i++) {
		fout << ans[i] << endl;
	}
	return 0;
}
