# flow
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables

// declare any functions
int convert_to_int(char ch){
	if(islower(ch)) return (ch-'a'+1);
	else return (ch-'A'+27);
}
int main() {
	// declare any local variables
	int N;
	int edge[60][60];
//	int path[60];
	vector<int> path[60];
	// initialize
	for(int i=1; i<=52; i++){
		for(int j=1; j<=52; j++) edge[i][j] = 0;
	}
	cin >> N;
	for(int i=1; i<=N; i++){
		char read_a,read_b; int read_cap;
		cin >> read_a >> read_b >> read_cap;
		int int_a = convert_to_int(read_a);
		int int_b = convert_to_int(read_b);
		edge[int_a][int_b] += read_cap;
		path[int_b].push_back(int_a);
	}
//  main
//	deletion:
	for(int k=1; k<=51; k++){
		for(int i=1; i<=51; i++){
			int counter = 0;
			for(int j=1; j<=52; j++){
				if(edge[i][j]!=0) counter++;
			}
			if(counter==0 && path[i].size()>=0){
				for(int x=0; x<path[i].size(); x++){
					edge[path[i][x]][i]=0;
				}
			}
		}
	}
//  merge
	for(int x=1; x<=52; x++){
		for(int i=1; i<=52; i++){
			int back_counter = 0;
			int p;
			for(int j=1; j<=52; j++){
				if(edge[i][j]!=0){
					p = j;
					back_counter++;
				}
			}
			if(back_counter == 1){
				int front_counter = 0;
				int c;
				for(int j=1; j<=52; j++){
					if(edge[j][i]!=0){
						c = j;
						front_counter++;
					}
				}
				if (front_counter == 1){
					edge[c][p] += min(edge[c][i],edge[i][p]);
					edge[c][i]=edge[i][p]=0;
				}
			}
		}
	}
	// output
	cout<<edge[27][52]<<endl;
	return 0;
}

```