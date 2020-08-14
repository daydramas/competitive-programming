#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
// structures / defines

// global variables
int N, M, K;
int L[2001], R[2001];
string sequence;
int ans = 0;
// functions
int main() {
	// local variables

	// input
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++) {
		cin >> L[i] >> R[i];
	}
	sequence = "";
	for(int i=0; i<M; i++) {
		string str; cin >> str;
		sequence += str;
	}

    map<int, int> seen;
    vector<int> moves;
    int in = 0, move = 1;
    while (seen.count(move) == 0) {
        seen[move] = in++;
        moves.push_back(move);
        for(int i=0; i<M; i++){
        	if(sequence[i] == 'L') move = L[move];
        	else move = R[move];
        }
        if(moves.size() > K) break;
    }
    if(moves.size() > K) cout << moves[K] << endl;
    else {
    	int C = in-seen[move];
		int nIn = (K-seen[move]+C)%C;
		cout << moves[seen[move]+nIn] << endl;
    }
	// output
	return 0;
}
