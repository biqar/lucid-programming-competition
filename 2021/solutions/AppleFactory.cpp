//
// Created by Islam, Abdullah Al Raqibul on 10/30/21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int _min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string in;
  vector<int> count(26, 0);

  getline(cin, in);
  //cin >> in;
  for(char ch : in) {
    if(ch >= 'a' && ch <= 'z') count[ch - 'a'] += 1;
  }

  // cout << "here I come\n";
  // cout << in << endl;

  // for(int i=0; i<26; i+=1) cout << count[i] << " ";
  // cout << endl;

  int ret = INT_MAX;
  ret = _min(ret, count['a' - 'a']);
  ret = _min(ret, (count['p' - 'a']/2));
  ret = _min(ret, count['l' - 'a']);
  ret = _min(ret, count['e' - 'a']);
  cout << ret;

  return 0;
}