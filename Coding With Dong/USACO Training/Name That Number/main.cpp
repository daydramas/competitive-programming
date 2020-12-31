/*
    ID: dongliu3
    PROG: namenum
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

string id;
map<char,vector<char>> m; // ex. {'2', {'A','B','C'}}
set<string> s;
vector<string> ans;

void comb(int i=0, string c="") {
    if(i==id.length()) {
        if(s.find(c) != s.end()) {
            ans.push_back(c);
        }
    }
    for(char ch : m[id[i]]) comb(i+1, c+ch);
}

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    fin >> id;
    m['2'] = {'A','B','C'};
    m['3'] = {'D','E','F'};
    m['4'] = {'G','H','I'};
    m['5'] = {'J','K','L'};
    m['6'] = {'M','N','O'};
    m['7'] = {'P','R','S'};
    m['8'] = {'T','U','V'};
    m['9'] = {'W','X','Y'};

    ifstream din("dict.txt");
    for(int i=0; i<4734; i++) {
        string t; din >> t;
        s.insert(t);
    }

    comb();
    if(ans.empty()) {
        fout << "NONE" << '\n';
    } else {
        for(string s : ans) fout << s << '\n';
    }
}