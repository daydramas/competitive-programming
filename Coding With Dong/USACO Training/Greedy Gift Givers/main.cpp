#include <bits/stdc++.h>
using namespace std;

int np;
map<string, int> names;
int money[20];

int main() {

    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    fin >> np;
    vector<string> namesl;
    for(int i=0; i<np; i++) {
        string name; fin >> name;
        names[name] = i;
        money[i] = 0;
        namesl.push_back(name);
    }
    for(int i=0; i<np; i++) {
        string sender; fin >> sender;
        int amount; fin >> amount;
        int num_people; fin >> num_people;
        vector<string> people;
        for(int j=0; j<num_people; j++) {
            string person; fin >> person;
            people.push_back(person);
        }
        if(num_people == 0) continue;
        int moneyGot = amount / num_people;
        money[names[sender]] -= moneyGot*num_people;
        for(int j=0; j<num_people; j++) {
            money[names[people[j]]] += moneyGot;
        }
    }
    for(int i=0; i<np; i++) {
        fout << namesl[i] <<" "<<money[i]<<"\n";
    }

}