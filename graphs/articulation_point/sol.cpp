/***
*   author:   5-head
*   created:  25.03.2021 19:12:54
***/

#include<bits/stdc++.h>

using namespace std;

class graph {
public:
  graph(int _n, int _m) {
    n = _n; m = _m;
  }
  void get_graph(int indexed = 1) {
    g.clear(); g.resize(n);
    edges.clear(); edges.resize(m);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u -= indexed;
      v -= indexed;
      g[u].push_back(edge(u, v, w));
      g[v].push_back(edge(v, u, w));
    }
  }
  struct edge {
    int from, to, dis;
    edge() : from(-1), to(-1), dis(0) {}
    edge(int f, int t) : from(f), to(t), dis(1) {}
    edge(int f, int t, int d) : from(f), to(t), dis(d) {}
  };
  static int n, m;
  static vector<vector<edge>> g;
  static vector<edge> edges;
};
int graph::n = {};
int graph::m = {};
vector<vector<graph::edge>> g = vector<vector<graph::edge>> ();
vector<graph::edge> edges = vector<graph::edge> ();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  return 0;
}