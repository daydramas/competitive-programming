<div align="center"> [art2.cpp](#0) | [cownomics.cpp](#1) </div>

# [art2.cpp](#0)
```cpp
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
int N;
int shell[100001];
int small[100001], big[100001];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("art2.in");
	ofstream fout("art2.out");

	// input
	fin >> N;
	for(int i=0; i<=N; i++) {
		small[i] = 1000000000;
		big[i] = -1;
	}
	for(int i=1; i<=N; i++) {
		fin >> shell[i];

		small[shell[i]] = min(small[shell[i]], i);
		big[shell[i]] = max(big[shell[i]], i);
	}
	// main
	stack<int> S;
	int ans = 0;
	for(int i=1; i<=N; i++) {
		int color = shell[i];
		if(color == 0) continue;
//		cout <<"color: "<<shell[i] << endl;
		if(small[color] == i) {
			S.push(color);
			ans = max(ans, (int)S.size());
		}
//		cout <<"top: "<<S.top() << endl;
		if(S.top() != color) {
//			cout << "weird" << endl;
			ans = -1;
			break;
		}
		if(big[color] == i) {
			S.pop();
		}
	}
	// output
	fout << ans << endl;
	return 0;
}

```

# [cownomics.cpp](#1)
```cpp
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
int N, M;
string spotty[501], plain[501];

//functions
bool possible(int sz) {
	int combo = M-sz+1;
//	cout << sz << " " << combo << endl;
	bool ans = false;
	for(int s=1; s<=combo; s++) {
		set<string> S; int tans = 0;
		for(int i=1; i<=N; i++) {
			S.insert(spotty[i].substr(s, sz));
		}
		tans = S.size();
		for(int i=1; i<=N; i++) {
			string mySUBSTRING = plain[i].substr(s, sz);
			if(S.count(mySUBSTRING)>0) {
				S.erase(mySUBSTRING);
			}
		}
		if(S.size() == tans) return true;
//		bool temp = true;
//		for(int i=1; i<=N; i++) {
//			string str = spotty[i].substr(s, sz);
//			for(int j=1; j<=N; j++) {
//				string str2 = plain[j].substr(s, sz);
//				if(str == str2) {
//					temp = false;
//					break;
//				}
//			}
//			if(!temp) break;
//		}
//		if(temp) return true;
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
		spotty[i] = " " + spotty[i];
	}
	for(int i=1; i<=N; i++) {
		fin >> plain[i];
		plain[i] = " " + plain[i];
	}

	// main
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



///*
//  _____     ______              ______                _______
// |     \   |      |  |\     |  |             |           |     |      |
// |	    \  |      |  | \    |  |             |           |     |      |
// |      |  |      |  |  \   |  |   ___       |           |     |      |
// |      |  |      |  |   \  |  |      |      |           |     |      |
// |      /  |      |  |    \ |  |      |      |           |     |      |
// |_____/   |______|  |     \|  |______|      |______  ___|___  |______|
//
//      ___   ___        ___             ___   ___   ___  ___
//  __ | __  |   | |    |   \   / |   | |___  |___| |    |   | \
//     |___| |___| |___ |___/   \ |___|  ___| |   | |___ |___| /
//
//*/
//
//#include <iostream>
//#include <map>
//#include <vector>
//#include <set>
//#include <queue>
//#include <algorithm>
//#include <iterator>
//#include <fstream>
//#include <cstring>
//#include <string>
//#include <iomanip>
//#include <iterator>
//#include <stack>
//#include <utility>
//using namespace std;
//
//// structures/defines
//
//// global variables
//int N, M;
//string spotty[501], plain[501];
//long long rollRandom[501], spottyHash[501], plainHash[501];
//
////functions
//
//int main() {
//	// local variables
//
//	// fstream
//	ifstream fin("cownomics.in");
//	ofstream fout("cownomics.out");
//
//	// input
//	fin >> N >> M;
//	for(int i=1; i<=N; i++) {
//		fin >> spotty[i];
//		spotty[i] = " "+spotty[i];
//	}
//	for(int i=1; i<=N; i++) {
//		fin >> plain[i];
//		plain[i] = " " + plain[i];
//	}
//	for(int i=1; i<=M; i++) {
//		rollRandom[i] = rand() % 1000000007;
//	}
//
//	// main
//	int i=1, j=1; bool d = true; int ans = M;
//	set<long long> hash;
//	while(j <= M) {
//		if(!d) {
////			cout << i << " " << j << endl;
//			ans = min(ans, j-i);
//		}
//		hash.clear();
//		if(d) {
//			d = false;
//			for(int k=1; k<=N; k++) {
//				spottyHash[k] += (rollRandom[j]*spotty[k][j])%1000000007;
//				hash.insert(spottyHash[k]);
//			}
//			for(int k=1; k<=N; k++) {
//				plainHash[k] += (rollRandom[j]*plain[k][j])%1000000007;
//				if(hash.count(plainHash[k])) {
//					d = true;
//				}
//			}
//			j++;
//		} else if (!d){
//			d = false;
//			for(int k=1; k<=N; k++) {
//				spottyHash[k] -= (rollRandom[i]*spotty[k][i])%1000000007;
//				hash.insert(spottyHash[k]);
//			}
//			for(int k=1; k<=N; k++) {
//				plainHash[k] -= (rollRandom[i]*plain[k][i])%1000000007;
//				if(hash.count(plainHash[k])) {
//					d = true;
//				}
//			}
//			i++;
//		}
//	}
//	// output
//	fout << ans << endl;
//	return 0;
//}



//
///*
//  _____     ______              ______                _______
// |     \   |      |  |\     |  |             |           |     |      |
// |	    \  |      |  | \    |  |             |           |     |      |
// |      |  |      |  |  \   |  |   ___       |           |     |      |
// |      |  |      |  |   \  |  |      |      |           |     |      |
// |      /  |      |  |    \ |  |      |      |           |     |      |
// |_____/   |______|  |     \|  |______|      |______  ___|___  |______|
//
//      ___   ___        ___             ___   ___   ___  ___
//  __ | __  |   | |    |   \   / |   | |___  |___| |    |   | \
//     |___| |___| |___ |___/   \ |___|  ___| |   | |___ |___| /
//
//*/
//
//#include <iostream>
//#include <map>
//#include <vector>
//#include <set>
//#include <bitset>
//#include <queue>
//#include <algorithm>
//#include <iterator>
//#include <fstream>
//#include <cstring>
//#include <string>
//#include <iomanip>
//#include <iterator>
//#include <stack>
//#include <utility>
//using namespace std;
//
//// structures/defines
//#define Pair pair<string, int>
//#define c first
////#define i second
//// global variables
//int N, M;
//bitset<1002> spotty[501], plain[501];
//vector<int> dp[501][501];
//vector<bitset<1002>> dp_s[501][501];
//
////functions
//bitset<1002> MY_SUB_SET(bitset<1002> os, int l, int r) {
//	bitset<1002> r_value;
////	int
//	for(int i=l; i<=r; i++) {
//		r_value.set(i-l, os[i]);
//	}
//	return r_value;
//}
//int main() {
//	// local variables
//
//	// fstream
//	ifstream fin("cownomics.in");
//	ofstream fout("cownomics.out");
//
//	// input
//	fin >> N >> M;
//	for(int i=1; i<=N; i++) {
//		string temp; fin >> temp;
//		for(int j=1; j<=M; j++) {
//			if(temp[j-1] == 'A') {
//				spotty[i].set(j*2-1, 0);
//				spotty[i].set(j*2, 0);
//			} else if (temp[j-1] == 'C') {
//				spotty[i].set(j*2-1, 0);
//				spotty[i].set(j*2, 1);
//			} else if (temp[j-1] == 'G') {
//				spotty[i].set(j*2-1, 1);
//				spotty[i].set(j*2, 0);
//			} else if (temp[j-1] == 'T') {
//				spotty[i].set(j*2-1, 1);
//				spotty[i].set(j*2, 1);
//			}
//		}
//		fout << spotty[i] << endl;
//	}
//	for(int i=1; i<=N; i++) {
//		string temp; fin >> temp;
//		for(int j=1; j<=M; j++) {
//			if(temp[j-1] == 'A') {
//				plain[i].set(j*2-1, 0);
//				plain[i].set(j*2, 0);
//			} else if (temp[j-1] == 'C') {
//				plain[i].set(j*2-1, 0);
//				plain[i].set(j*2, 1);
//			} else if (temp[j-1] == 'G') {
//				plain[i].set(j*2-1, 1);
//				plain[i].set(j*2, 0);
//			} else if (temp[j-1] == 'T') {
//				plain[i].set(j*2-1, 1);
//				plain[i].set(j*2, 1);
//			}
//		}
//	}
////	// main
//	for(int i=0; i<=M; i++) {
//		for(int j=0; j<=M; j++) {
//			dp[i][j].push_back(-1);
//			dp_s[i][j].push_back(0);
//		}
//	}
//
//	int K = 501;
//	for(int i=1; i<=M; i++) {
//		if(K == 501) {
//			for(int j=i; j>=1; j--) {
//				dp[i][i-j+1].clear();
////				cout << i << " " << j << endl;
//				int nk = i-j;
//				for(int k=0; k<dp[i-1][nk].size(); k++) {
//					int in=dp[i-1][nk][k];
//					if(in == -1) {
//						for(int l=1; l<=N; l++) {
////							string str = dp[i-1][i-j+1][k].c+string(1, spotty[l][i]);
//							bitset<1002> str = MY_SUB_SET(spotty[l], 2*j, 2*i-1);
////							bitset<1002> bit1 =
//							for(int m=1; m<=N; m++) {
////								cout<<i<<" " << j<<" : "<<str<<" and " << plain[m].substr(j, i-j+1) << endl;
////								if(str == plain[m].substr(j, i-j+1)) {
//								if(str == MY_SUB_SET(plain[m], 2*j, 2*i-1)) {
////									cout<<i<<" " << j<<" : " << plain[m].substr(j, i-j+1) << endl;
//									dp[i][i-j+1].push_back(l);
//									break;
//								}
////
//							}
//						}
//					} else {
////						string str = spotty[in].substr(j, i-j+1);
//						bitset<1002> str = MY_SUB_SET(spotty[in], 2*j, 2*i-1);
//////								string(1, spotty[in][i]);
////						cout << str << endl;
//						for(int m=1; m<=N; m++) {
//							if(str == MY_SUB_SET(plain[m], 2*j, 2*i-1)) {
////								cout<<i<<" " << j<<" : "<<str<<" and " << plain[m].substr(j, i-j+1) << endl;
//								dp[i][i-j+1].push_back(in);
//								break;
//							}
////
//						}
//					}
//				}
//				if(dp[i][i-j+1].empty()) {
////					cout <<"K: "<<i<<" "<<j<<endl;
//					K = min(K, i-j+1);
//				}
//			}
//		} else {
//			for(int j=i; j>=i-K+1; j--) {
//				dp[i][i-j+1].clear();
//				int nk = i-j;
//				for(int k=0; k<dp[i-1][nk].size(); k++) {
//					int in=dp[i-1][nk][k];
//					if(in == -1) {
//						for(int l=1; l<=N; l++) {
//							bitset<1002> str = MY_SUB_SET(spotty[l], 2*j, 2*i-1);
//							for(int m=1; m<=N; m++) {
//								if(str == MY_SUB_SET(plain[m], 2*j, 2*i-1)) {
//									dp[i][i-j+1].push_back(l);
//									break;
//								}
////
//							}
//						}
//					} else {
//						bitset<1002> str = MY_SUB_SET(spotty[in], 2*j, 2*i-1);
//
////
//						for(int m=1; m<=N; m++) {
//							if(str == MY_SUB_SET(plain[m], 2*j, 2*i-1)) {
////								cout<<i<<" " << j<<" : "<<str<<" and " << plain[m].substr(j, i-j+1) << endl;
//								dp[i][i-j+1].push_back(in);
//								break;
//							}
////
//						}
//					}
//				}
//				if(dp[i][i-j+1].empty()) {
//					K = min(K, i-j+1);
//				}
//			}
//		}
//	}
////	// output
//	fout << K << endl;
//	return 0;
//}

```

