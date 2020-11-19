/*
 * Description: Finds occurrences of a string in another string
 * Time: O(N)
 * Source: GeeksForGeeks
*/

#include <bits/stdc++.h>
using namespace std;

void solveLps(string &a, int &n, vector<int> &lps);

void KMP (string &a, string &b) {
    int n = a.length(), m = b.length();
    vector<int> lps(m+1); solveLps(b, m, lps);

    int i=0, j=0;
    while(i<n) {
        if (a[i]==b[j]) j++, i++;
        if (j==m) { 
            cout <<"Found at idx "<<i-j<<"\n";
            j=lps[j-1]; 
        } 
        else if (i<n && b[j]!=a[i]) { 
            if (j!=0) j=lps[j-1]; 
            else i++; 
        } 
    }
}

void solveLps(string &a, int &n, vector<int> &lps) {
    lps[0] = 0;
    int len=0, i=1;
    while(i < n) {
        if (a[i] == a[len]) lps[i] = ++len, i++; 
        else { 
            if (len != 0) len = lps[len-1]; 
            else lps[i++]=0;
        } 
    }

}