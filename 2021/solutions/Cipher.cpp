//
// Created by Islam, Abdullah Al Raqibul on 10/30/21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int col;
  vector<int> cnum;
  string msg;
  string ret = "";

  getline(cin, msg);
  col = stoi(msg);

  getline(cin, msg);
  stringstream ss(msg);
  int tmp;
  while(ss >> tmp) cnum.push_back(tmp);

  //cin.ignore();
  getline(cin, msg);

  //cout << msg << endl;

  int len = msg.length();
  for(int i=0; i<col; i+=1) {
    for(int j=cnum[i]-1; j<len; j+=col) ret += msg[j];
  }
  cout << ret << endl;

  return 0;
}