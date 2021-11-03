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

struct Profile {
  string name;
  double amount;
  int pos;

  Profile() {}
  Profile(string _n, double _a, int _p) {
    name = _n;
    amount = _a;
    pos = _p;
  }

  bool operator<( const Profile& rhs ) const {
    return name < rhs.name;
  }
};

double distribute(int u, double prof, double keep, vector<Profile>& ret, vector<int>& par, vector<double>& share) {
  if(par[u] == -1) {
    double remain = prof - (prof * keep);
    ret[u].amount += (prof * keep);
    // cout << "remain from jude: " << remain << endl;
    return remain;
  }

  double got_from_boss = distribute(par[u], prof, share[u], ret, par, share);
  double remain = got_from_boss - (got_from_boss * keep);
  ret[u].amount += (got_from_boss * keep);
  return remain;
}


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n = 0, e;
  vector<Profile> ret;
  vector<int> par;
  vector<double> share;
  map<string, int> m;

  m["Jude"] = n;
  par.push_back(-1);
  share.push_back(1.0);
  ret.push_back(Profile("Jude", 0.0, n));
  n += 1;

  string emp, boss;
  int tmp, ei, bi;
  cin >> e;
  for(int i=0; i<e; i+=1) {
    cin >> emp >> boss >> tmp;

    if(m.find(boss) == m.end()) {
      m[boss] = n;
      par.push_back(-1);
      share.push_back(1.0);
      ret.push_back(Profile(boss, 0.0, n));
      bi = n;
      n += 1;
    }
    else bi = m[boss];

    if(m.find(emp) == m.end()) {
      m[emp] = n;
      par.push_back(-1);
      share.push_back(1.0);
      ret.push_back(Profile(emp, 0.0, n));
      ei = n;
      n += 1;
    }
    else ei = m[emp];

    par[ei] = bi;
    share[ei] = (double) (100 - tmp) / 100.0;
  }

  // for(int i=0; i<n; i+=1) {
  //     cout << ret[i].name << " " << ret[i].pos << endl;
  //     cout << par[i] << " " << share[i] << endl;
  //     cout << endl;
  // }

  double prof;
  cin >> e;
  for(int i=0; i<e; i+=1) {
    cin >> emp >> prof;
    distribute(m[emp], prof, 1.0, ret, par, share);
  }

  sort(ret.begin(), ret.end());
  for(int i=0; i<n; i+=1) {
    cout << ret[i].name << " " << (int) (ret[i].amount + 0.5) << endl;
  }

  return 0;
}

