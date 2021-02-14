#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
string str;

//functions
bool iseven(char ch) {
	int i = ch-'0';
	return i%2 == 0;
}
int main() {
	//local variables

	//input
	cin >> str;

	//main
	int ans = 0;
	if (iseven(str[str.size()-1])) {
		ans = 0;
	} else {
		ans = 1;
	}
	//output
	cout << ans << endl;
	return 0;
}
