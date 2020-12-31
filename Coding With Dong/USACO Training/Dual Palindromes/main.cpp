/*
    ID: dongliu3
    PROG: dualpal
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, s;

char ch(int nm) {
    return ('0'+nm);
}

string convert(int decimal, int base) {
    string result = "";
    while(decimal) {
        result = string(1, ch(decimal % base)) + result;
        decimal /= base;
    }
    return result;
}
bool palindrome(string s) {
    int i=0, j=s.length()-1;
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

int main() {

    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    fin >> n >> s;
    for(++s; n; s++) {
        int cnt=0;
        for(int b=2; b<=10; b++) {
            if(palindrome(convert(s, b))) {
                cnt++;
            }
        }
        if(cnt>=2) {
            fout << s << "\n";
            n--;
        }
    }
}