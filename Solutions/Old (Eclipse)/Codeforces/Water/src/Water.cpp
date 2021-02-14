//#include <bits/stdc++.h>
//
//using namespace std;
//
////structures/defines
//#define ll long long
//
////global variables
//
////functions
//void solve() {
//	int h, c, t;
//	cin >> h >> c >> t;
//	double diff = 1000000000.0;
//	double first = (h+c)/(2.0);
//	if (first >= t) {
//		cout << "2" << endl;
//		return;
//	}
//	first = abs(first-t);
//
//	int cnt = 0;
//	if ((t-h)%(h+c-(2*t))) cnt = 1;
//	int n = (t-h)/(h+c-(2*t)) + cnt;
//	cout << "N: "<<n << endl;
//	if (n == 0) {
//		double second = abs(h-t);
//		if (second < first) cout << "1" << endl;
//		else cout <<"2"<<endl;
//	} else if (n==1) {
//		double second = (h*(n)+c*(n-1))/(double)(2*(n-1) + 1);
//		second = abs(second-t);
//		if (second < first) cout << "1" << endl;
//		else cout <<"2"<<endl;
//	} else {
//		double second = (h*(n)+c*(n-1))/(double)(2*(n-1) + 1);
//		second = abs(second-t);
//
//		double third = (h*(n-1)+c*(n-2))/(double)(2*(n-2) + 1);
//		third = abs(third-t);
//
//		cout <<first<<" "<<second<<" "<<third<<endl;
//		if (second < first && second < third) {
//			cout << 2*(n-1) + 1 << endl;
//		} else if (third < first && third < second) {
//			cout << 2*(n-2) + 1 << endl;
//		} else {
//			cout <<"2"<<endl;
//		}
//	}
//
//}
//int main() {
//	//local variables
//
//	//input
//	int t; cin >> t;
//	for (int i=0; i<t; i++) solve();
//
//	//main
//
//	//output
//
//	return 0;
//}



#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int h, c, t;
	cin >> h >> c >> t;

	double first = (h+c)/(2.0);
	if (first >= t) {
		cout << "2" << endl;
		return;
	}
	first = abs(first-t);

	int cnt = 0;
	if ((2*h + c - 3*t) / (2*t - h - c) != 0) cnt = 1;
//	int n = (t-h)/(h+c-(2*t)) + cnt;
	int n = (2*h + c - 3*t) / (2*t - h - c);
	if (n < 0) {
		n = 0;
	} else n += cnt;
//	cout << "N: "<<n << endl;
	if (n == 0) {
		cout << "1" <<endl;
//	} else if (n==1) {
//		double second = (h*(n)+c*(n-1))/(double)(2*(n-1) + 1);
//		second = abs(second-t);
//		if (second < first) cout << "1" << endl;
//		else cout <<"2"<<endl;
	} else {
		double second = (h*(n+1)+c*(n))/(double)(2*(n) + 1);
		second = abs(second-t);

		double third = (h*(n+2)+c*(n+1))/(double)(2*(n+1) + 1);
		third = abs(third-t);

//		cout <<first<<" "<<second<<" "<<third<<endl;
		if (second == third) {
			if (second < first) cout << 2*(n) + 1 << endl;
//			else if (second == first) cout << "2"<<endl;
			else cout << "2"<<endl;
			return;
		}
		if (second < first && second < third) {
			cout << 2*(n) + 1 << endl;
		} else if (third < first && third < second) {
			cout << 2*(n+1) + 1 << endl;
		} else {
			cout <<"2"<<endl;
		}
	}

}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=0; i<t; i++) solve();

	//main

	//output

	return 0;
}
