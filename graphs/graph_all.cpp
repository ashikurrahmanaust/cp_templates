#include<bits/stdc++.h>

using namespace std;

struct node { 
  int to, cost;
  node() {
    to = -1; cost = 0;
  }
  node(int v) {
    to = v; cost = 1;
  }
  node (int v, int c) {
    to = v; cost = c;
  }
};

class graph {
public:
  int n, m;
  vector<vector<node>> g;
  graph(int _n, int _m) {
    n = _n; m = _m;
    g.clear();
    g.resize(n);
  }
  void get_dir_graph() {
    for (int i = 0; i < m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      x--; y--;
      #warning("check carefully in case of zero indexed input");
      g[x].push_back(node(y, w));                                                              
    }
  }
  void get_undir_graph() {
    for (int i = 0; i < m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      x--; y--;
      #warning("check carefully in case of zero indexed input");
      g[x].push_back(node(y, w));
      g[y].push_back(node(x, w));
    }
  }                
};

int main(){      
  
  return 0;
}