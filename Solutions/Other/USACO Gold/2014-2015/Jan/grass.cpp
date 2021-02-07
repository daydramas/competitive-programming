/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
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

// declare any structures
#define pii pair<int, pair<int, bool> >
// declare any global variables
int N, M;
vector <int> path_from[100010];
vector <int> path_to[100010];
bool visited[100010];
// declare any functions
int main() {

	// fstream
	ifstream fin ("grass.in");
	ofstream fout ("grass.out");

	// input
	fin >> N >> M;
	for(int i=1; i<=M; i++){
		int from, go; fin >> from >> go;
		path_from[from].push_back(go);
		path_to[go].push_back(from);
	}
	for(int i=1; i<=N; i++){

	}
	// main
//	priority_queue<pii> pq;
	queue<pii> pq;
	pq.push(make_pair(0, make_pair(1, false)));

	while(!pq.empty()){
		int farms_visited = pq.front().first;
		int barn = pq.front().second.first;
		bool back_yet = pq.front().second.second;
		pq.pop();

		visited[barn] = true;

//		cout << barn << endl;
		if(barn == 1 and farms_visited != 0){
			cout << farms_visited << endl;
			break;
		}

		for(int i=0; i<path_from[barn].size(); i++){
			int go = path_from[barn][i];
			if(!visited[go]){
				cout << barn << " push "<< go << farms_visited + 1<< endl;
				pq.push(make_pair(farms_visited+1, make_pair(go, back_yet)));
			}
		}
		if(!back_yet){
			for(int i=0; i<path_to[barn].size(); i++){
				int go = path_to[barn][i];
				if(!visited[go]){
					pq.push(make_pair(farms_visited+1, make_pair(go, true)));
					cout << barn << " push "<< go << farms_visited + 1<< endl;
				} else {
					pq.push(make_pair(farms_visited, make_pair(go, true)));
					cout << barn << " push "<< go << farms_visited << endl;
				}
			}
		}
	}
	// output

	//close
	fout.close();
	return 0;
}
