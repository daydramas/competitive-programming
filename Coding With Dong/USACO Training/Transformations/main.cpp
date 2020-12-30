/*
    ID: dongliu3
    PROG: transform
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n;

struct Grid {
    int n;
    vector<vector<char>> p;
    Grid(int _n) {
        n = _n;
        p.assign(n, vector<char>(n, ' '));
    }
    // equals
    bool eq(Grid* other) {
        // compare
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(p[i][j] != other->p[i][j]) return false;
        return true;
    }
    // rotate 90
    Grid* r90() {
        Grid* result = new Grid(n);
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            // before -> after => (i,j) -> (j,n-i-1)
            result->p[j][n-i-1] = p[i][j];
        return result;
    }
    // reflect
    Grid* rf() {
        Grid* result = new Grid(n);
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            // before -> after => (i,j) -> (i,n-j-1)
            result->p[i][n-j-1] = p[i][j];
        return result;
    }
};

int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    fin >> n;
    Grid* before = new Grid(n);
    Grid* after = new Grid(n);
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        fin >> before->p[i][j];
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        fin >> after->p[i][j];

    if(after->eq(before->r90())) { // r90
        fout << "1\n";
    } else if(after->eq(before->r90()->r90())) { // r180
        fout << "2\n";
    } else if(after->eq(before->r90()->r90()->r90())) { // r270
        fout << "3\n";
    } else if(after->eq(before->rf())) { // reflect
        fout << "4\n";
    } else if(after->eq(before->rf()->r90())) { // reflect r90
        fout <<"5\n";
    } else if(after->eq(before->rf()->r90()->r90())) { // reflect r180
        fout <<"5\n";
    } else if(after->eq(before->rf()->r90()->r90()->r90())) { // reflect r270
        fout <<"5\n";
    } else if(after->eq(before)){ // equals
        fout <<"6\n";
    } else { // if not the ones above
        fout <<"7\n";
    }
}