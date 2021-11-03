//
// Created by Islam, Abdullah Al Raqibul on 10/30/21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_valid(int i, int j, int r, int c) {
  if(i >= 0 && i<r && j>=0 && j<c) return true;
  return false;
}

void discover(int i, int j, int r, int c, vector<vector<int>>& map) {
  for(int p=0; p<4; p+=1) {
    int ii = i + dx[p];
    int jj = j + dy[p];
    if(is_valid(ii, jj, r, c) && map[ii][jj] != -1) {
      if(map[i][j] + 1 < map[ii][jj]) {
        map[ii][jj] = map[i][j] + 1;
        discover(ii, jj, r, c, map);
      }
    }
  }
}


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int r, c;
  cin >> r >> c;
  vector<vector<int>> map(r, vector<int>(c));

  for(int i=0; i<r; i+=1) {
    for(int j=0; j<c; j+=1) {
      cin >> map[i][j];
    }
  }

  for(int i=0; i<r; i+=1) {
    for(int j=0; j<c; j+=1) {
      if(map[i][j] == 0) discover(i, j, r, c, map);
    }
  }

  for(int i=0; i<r; i+=1) {
    for(int j=0; j<c; j+=1) {
      if(j) cout << " ";
      cout << map[i][j];
    }
    cout << endl;
  }
  return 0;
}

