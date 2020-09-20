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
#define ll long long
#define pii pair<long long, long long>
#define x first
#define y second
// declare any global variables
long long N;
pii cow[1010];
bool visited[1010];
// declare any functions
bool dist(long long i, long long j, long long X){
	long long d = (cow[i].x-cow[j].x)*(cow[i].x-cow[j].x) + (cow[i].y-cow[j].y)*(cow[i].y-cow[j].y);
	return (d <= X);
}
bool mst(long long X){
	long long connected = 0;
	queue<long long> solver; solver.push(1);
	memset(visited, false, sizeof(bool)*(N+1));
	visited[1] = true;
//	cout << "pushing 1"<<endl;
	while(!solver.empty()){
		long long in = solver.front();
		solver.pop();
		connected++;

		for(long long i=1; i<=N; i++){
			if(!visited[i] && dist(in, i, X)){
				solver.push(i);
//				cout << "pushing "<< i<<endl;
				visited[i] = true;
			}
		}
	}
	return (connected >= N);
}
int main() {

	// fstream
	ifstream fin ("moocast.in");
	ofstream fout ("moocast.out");

	// input
	fin >> N;
	for(long long i=1; i<=N; i++) fin >> cow[i].x >> cow[i].y;
	// main
	long long low = 0, high = 1000000000;
	while(low < high && low != high){
		long long mid = (low+high)/2;
//		cout << low << " " << high << " " << mid << endl;
		if(mst(mid)){
			high = mid;
		} else low = mid+1;
	}
	// output
	fout << low << endl;
	//close
	fout.close();
	return 0;
}
