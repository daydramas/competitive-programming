#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MAX_N 20001

int N;
map<int, int> possible[5];
int line[MAX_N];

bool compare(int a, int b) {
  int r_value = 0;
  for(int i=0; i<5; i++) {
    if(possible[i][a] < possible[i][b]) r_value++;
  }
  return r_value > 2;
}
int main() {

  cin >> N;
  for(int i=0; i<5; i++) {
    for(int j=0; j<N; j++) {
      int read; cin >> read;
      possible[i][read]=j;
      line[j]=read;
    }
  }

  sort(line, line+N, compare);

  for(int i=0; i<N; i++) {
    cout << line[i] << endl;
  }

}
