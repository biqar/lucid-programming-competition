//
// Created by Islam, Abdullah Al Raqibul on 10/30/21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, tmp;
  cin >> n;
  map<int, int> mp;
  for(int i=0; i<n; i+=1) {
    cin >> tmp;
    mp[tmp] += 1;
  }

  bool flg = false;
  int target = ceil((n * 2) / 3);
  map<int, int>::iterator it;
  for(it = mp.begin(); it != mp.end(); it++) {
    if(it->second > target) {
      flg = true;
      break;
    }
  }
  cout << (flg == false ? "False" : "True") << endl;
  return 0;
}

