/*
    ID: dongliu3
    PROG: palsquare
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int B;

char convert_char(int n) {
    if(n>=0 && n<=9) return ('0'+n);
    else return ('A'+n-10);
}
string convert(int decimal) {
    string result = "";
    while(decimal > 0) {
        result = string(1, convert_char(decimal%B)) + result;
        decimal /= B;
    }
    return result;
}
bool palindromic(string s) {
    int i=0, j=s.length()-1;
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}
int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    fin >> B;
    for(int i=1; i<=300; i++) {
        string c=convert(i), cs=convert(i*i);
        if(palindromic(cs)) {
            fout << c << " " << cs << "\n";
        }
    }
}