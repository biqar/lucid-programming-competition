//
// Created by Islam, Abdullah Al Raqibul on 10/30/21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Elem {
  int pos;
  int sc;
  int neigh;
  int weight;

  Elem() {}
  Elem(int _p, int _s, int _n) {
    pos = _p;
    sc = _s;
    neigh = _n;
  }

  bool operator<( const Elem& rhs ) const {
    return sc > rhs.sc;
    //return weight < rhs.weight;

    // if(neigh == rhs.neigh) return sc < rhs.sc;
    // return neigh < rhs.neigh;

    // if(sc == rhs.sc) return neigh < rhs.neigh;
    // return sc < rhs.sc;
  }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, tmp;
  cin >> n;

  vector<Elem> s(n);
  vector<int> ju(n);
  vector<int> vis(n, 0);
  vector<vector<int>> adj(n, vector<int>(n, 0));

  for(int i=0; i<n; i+=1) {
    cin >> tmp;
    s[i].pos = i;
    s[i].sc = tmp;
    s[i].neigh = 0;
    ju[i] = tmp;
  }

  // for(int i=0; i<n; i+=1) {
  //     cout << s[i].pos << " " << s[i].sc << " " << s[i].neigh << endl;
  // }

  for(int i=0; i<n; i+=1) {
    for(int j=0; j<n; j+=1) {
      cin >> tmp;
      adj[i][j] = tmp;
      if(tmp) {
        s[i].neigh += 1;
        s[i].weight += ju[j];
      }
    }
  }

  sort(s.begin(), s.end());

  // for(int i=0; i<n; i+=1) {
  //     cout << s[i].pos << " " << s[i].sc << " " << s[i].neigh << endl;
  // }

  int ret = 0;
  for(int i=0; i<n; i+=1) {
    ret += s[i].sc;
    for(int j=0; j<n; j+=1) {
      if(adj[s[i].pos][j] && vis[j]) ret += ju[j];
    }
    vis[s[i].pos] = 1;
  }

  cout << ret << endl;

  return 0;
}

