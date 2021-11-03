//
// Created by Islam, Abdullah Al Raqibul on 10/30/21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  vector<int> ret;
  int ln = 1;
  string line;
  while(getline(cin, line)) {
    if(line[0] >= 'A' && line[0] <= 'Z') {
      int l = line.length();
      if(line[l-1] != '.') ret.push_back(ln);
      else {
        for(int i=0; i<l; i+=1) {
          if(line[i] == '.' && i != l-1) {
            ret.push_back(ln);
            break;
          }
          if(line[i] == ' ' && i+1 < l && line[i+1] == ' ') {
            ret.push_back(ln);
            break;
          }
          if(line[i] == ','
             && (line[i-1] == ' ' || line[i-1] == ',' || line[i-1] == '.')) {
            ret.push_back(ln);
            break;
          }
          if(line[i] == ',' && i+1 < l && line[i+1] != ' ') {
            ret.push_back(ln);
            break;
          }
        }
      }
    }
    else {
      ret.push_back(ln);
    }
    ln += 1;
  }

  //cout << ln << endl;
  int len = ret.size();
  if(len == 0) cout << "No Problems\n";
  else {
    for(int i=0; i<len; i+=1) {
      if(i) cout << " ";
      cout << ret[i];
    }
    cout << endl;
  }
  return 0;
}

