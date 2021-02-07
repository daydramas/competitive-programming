/**
 * billboard
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int x11, y11, x21, y21;
	int x12, y12, x22, y22;

	ifstream fin("billboard.in");
	ofstream fout("billboard.out");

	fin >> x11 >> y11 >> x21 >> y21;
	fin >> x12 >> y12 >> x22 >> y22;

	if((y11>=y22)and(y11<=y12)){
		if((x12<=x11)and(x22>=x21)){
			y11+=y11-y12;
		}
	}
	if((y21<=y22)and(y21>=y12)){
		if((x12<=x11)and(x22>=x21)){
			y21-=y21-y12;
		}
	}
	if((x21>=x12)and(x21<=x22)){
		if((y22>=y21)and(y21<=y11)){
			x21-=x21-x12;
		}
	}
	if((x11>=x12)and(x11<=x22)){
		if((y22>=y21)and(y11>=y12)){
			x11+=x22-x11;
		}
	}
	int area=0;
	for(int i=x11; i<x21; i++){
		for(int j=y11; j<y21; j++){
			area++;
		}
	}
	fout << area;
	return 0;
}