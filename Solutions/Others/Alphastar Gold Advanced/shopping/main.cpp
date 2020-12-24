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
#define Pair pair<int, int>
#define productCode first
#define items second
struct offer {
	int numberProducts, reducedPrice;
	vector<Pair> products;
};
struct product {
	int code, purchased, price;
};
// global variables
int S, B;
offer offers[100];
// functions
product products[6];
int index1[1000];
int dp[6][6][6][6][6];
int main() {
	// local variables
	for(int a=0; a<=5; a++) {
		for(int b=0; b<=5; b++) {
			for(int c=0; c<=5; c++) {
				for(int d=0; d<=5; d++) {
					for(int e=0; e<=5; e++) {
						dp[a][b][c][d][e] = 1000000000;
					}
				}
			}
		}
	}
	// input
	cin >> S;
	for(int i=1; i<=S; i++) {
		cin >> offers[i].numberProducts;

		for(int j=1; j<=offers[i].numberProducts; j++) {
			int Code, Item; cin >> Code >> Item;
			offers[i].products.push_back(Pair(Code, Item));
		}
		cin >> offers[i].reducedPrice;
	}
	cin >> B;
	for(int i=1; i<=B; i++) {
		cin >> products[i].code >> products[i].purchased >> products[i].price;
		index1[products[i].code] = i;
	}
	for(int i=B+1; i<=5; i++) {
		products[i].code = -1, products[i].purchased = 0, products[i].price = 1000000000;
	}
	// main
	dp[0][0][0][0][0] = 0;
	for(int i=1; i<=S; i++) {
		int pa, pb, pc, pd, pe; pa=pb=pc=pd=pe=0;
		for(int j=0; j<offers[i].numberProducts; j++) {
			int in = index1[offers[i].products[j].productCode];
			if (in == 1) pa += offers[i].products[j].items;
			if (in == 2) pb += offers[i].products[j].items;
			if (in == 3) pc += offers[i].products[j].items;
			if (in == 4) pd += offers[i].products[j].items;
			if (in == 5) pe += offers[i].products[j].items;
		}
		for(int a=0; a<=5; a++) {
			for(int b=0; b<=5; b++) {
				for(int c=0; c<=5; c++) {
					for(int d=0; d<=5; d++) {
						for(int e=0; e<=5; e++) {
							int na=a+pa, nb=b+pb, nc=c+pc, nd=d+pd, ne=e+pe;
							if(na<=products[1].purchased && nb<=products[2].purchased && nc<=products[3].purchased && nd<=products[4].purchased && ne<=products[5].purchased) {
								dp[na][nb][nc][nd][ne] = min(dp[na][nb][nc][nd][ne], dp[a][b][c][d][e]+offers[i].reducedPrice);
							}
						}
					}
				}
			}
		}
	}
	for(int i=1; i<=B; i++) {
		int pa, pb, pc, pd, pe; pa=pb=pc=pd=pe=0;
		if (i == 1) pa += 1;
		if (i == 2) pb += 1;
		if (i == 3) pc += 1;
		if (i == 4) pd += 1;
		if (i == 5) pe += 1;
		for(int a=0; a<=5; a++) {
			for(int b=0; b<=5; b++) {
				for(int c=0; c<=5; c++) {
					for(int d=0; d<=5; d++) {
						for(int e=0; e<=5; e++) {
							int na=a+pa, nb=b+pb, nc=c+pc, nd=d+pd, ne=e+pe;
							if(na<=products[1].purchased && nb<=products[2].purchased && nc<=products[3].purchased && nd<=products[4].purchased && ne<=products[5].purchased) {
								dp[na][nb][nc][nd][ne] = min(dp[na][nb][nc][nd][ne], dp[a][b][c][d][e]+products[i].price);
							}
						}
					}
				}
			}
		}
	}
	// output
	cout << dp[products[1].purchased][products[2].purchased][products[3].purchased][products[4].purchased][products[5].purchased] << endl;
	return 0;
}
