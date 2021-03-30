/***
*   author:   5-head
*   created:  25.03.2021 19:33:16
***/

#include<bits/stdc++.h>

using namespace std;

class tree {
public:
  tree(int _n) {
    n = _n;
  }
  void get_tree() {
    g.clear(); g.resize(n);
    edges.clear(); edges.resize(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      assert(u >= 0 && v >= 0 && u < n && v < n);
      g[u].push_back(edge(u, v));
      g[v].push_back(edge(v, u));
    }
  }
  struct edge {
    int from, to, dis;
    edge() {
      from = to = dis = -1;
    }
    edge(int f, int t) {
      from = f; to = t; dis = 1;
    } 
    edge(int f, int t, int c) {
      from = f; to = t; dis = c;
    }
  };
  static int n;
  static vector<vector<edge>> g;
  static vector<edge> edges;
};                                                                 
int tree::n = {};
vector<tree::edge> tree::edges = vector<tree::edge> ();
vector<vector<tree::edge>> tree::g = vector<vector<tree::edge>> ();


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}