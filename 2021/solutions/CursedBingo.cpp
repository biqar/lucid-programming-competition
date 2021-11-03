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
  int t;
  long long int x;
  cin >> t;
  for(int i=0; i<t; i+=1) {
    cin >> x;
    cout << x * (x-1) << endl;
  }
  return 0;
}

