#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

// declare any structures
int max0(int a, int b){
    if (a>b) return a;
    return b;
}
// declare any global variables
int N; int B;
int ans = 0;
map<int, map<int, int> > grid;
map<int, map<int, int> > visited;
int X[5] = {0, 1, 0, -1, 0};
int Y[5] = {0, 0, 1, 0, -1};
int change1(int i){
    if(i==3) return 4;
    return (i+1)%4;
}
int change2(int i){
    if(i==1) return 4;
    return (i+3)%4;
}
/*
 * direction:
 * 1) down
 * 2) right
 * 3) up
 * 4) left
 */

void recurse(int i, int j, int counter, int direction){
    counter++;
    ans = max0(counter, ans);
    //    cout<<i<<" "<<j<<" = "<<counter<<endl;
    visited[i][j] = 1;
    if(direction == 0){
        for(int k=1; k<=4; k++){
            int x = i+X[k]; int y = j+Y[k];
            if(x<1 || x>N || y<1 || y>N){
                continue;
            } else if(visited[x][y]){
                continue;
            } else if(grid[x][y] == 0){
                recurse(x, y, counter, k);
            }
        }
    } else if (direction != 0){
        int x = i+X[direction]; int y = j+Y[direction];
        if(x<1 || x>N || y<1 || y>N || grid[x][y] == 1){
            if(i+X[change1(direction)] >= 1 && i+X[change1(direction)] <= N){
                if(j+Y[change1(direction)] >= 1 && j+Y[change1(direction)] <= N){
                    if(!visited[i+X[change1(direction)]][j+Y[change1(direction)]] && grid[i+X[change1(direction)]][j+Y[change1(direction)]] == 0){
                        recurse(i+X[change1(direction)], j+Y[change1(direction)],counter, change1(direction));
                    }
                }
            }
            if(i+X[change2(direction)] >= 1 && i+X[change2(direction)] <= N){
                if(j+Y[change2(direction)] >=1 && j+Y[change2(direction)] <= N){
                    if(!visited[i+X[change2(direction)]][j+Y[change2(direction)]] && grid[i+X[change2(direction)]][j+Y[change2(direction)]] == 0){
                        recurse(i+X[change2(direction)], j+Y[change2(direction)],counter, change2(direction));
                    }
                }
            }
        } else if (grid[x][y]==0 && !visited[x][y]){
            recurse(x,y,counter, direction);
        }
    }
    visited[i][j] = 0;
}
int main() {
    
    char read;
    int col;
    
    cin >> N >> B;
    
    for(int i=1; i<=B; i++){
        cin >> read >> col;
        grid[col][int(read-'A'+1)] = 1;
    }
    // main
    recurse(1, 1, 0, 0);
    // output
    cout<< ans<<endl;
    return 0;
}
