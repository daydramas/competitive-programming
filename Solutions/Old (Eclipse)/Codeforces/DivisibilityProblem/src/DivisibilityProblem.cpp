#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int T, a, b;

//functions

int main() {
	//local variables

	//input
	cin >> T;
	for (int i=1; i<=T; i++) {
		cin >> a >> b;
		if (a%b == 0) {
			cout <<"0"<<endl;
			continue;
		}
		int diff = b*((a/b)+1) - a;
		cout <<diff<<endl;
	}
	//main

	//output

	return 0;
}
