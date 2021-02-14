#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int a,b,s;

//functions

int main() {
	//local variables

	//input
	cin >> a >> b >> s;

	//main
	bool ok = (abs(a)+abs(b))<=s & !((abs(a)+abs(b)-s)%2);
	cout << (ok?"Yes":"No") << endl;
	//output

	return 0;
}
